#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "baseHeaders.h"
#include "dt_recv2.h"

// TODO: move into netvar class
class netvar_tree
{
	struct node;
	using map_type = std::unordered_map<std::string, std::shared_ptr<node>>;

	struct node
	{
		node (int offset, RecvProp *p)
		    : offset (offset), prop (p)
		{
		}
		map_type  nodes;
		int       offset;
		RecvProp *prop;
	};

	map_type nodes;

public:
	// netvar_tree ( );

	void init ();

private:
	void populate_nodes (class RecvTable *recv_table, map_type *map);

	/**
     * get_offset_recursive - Return the offset of the final node
     * @map:	Node map to scan
     * @acc:	Offset accumulator
     * @name:	Netvar name to search for
     *
     * Get the offset of the last netvar from map and return the sum of it and accum
     */
	int get_offset_recursive (map_type &map, int acc, const char *name)
	{
		return acc + map[name]->offset;
	}

	/**
     * get_offset_recursive - Recursively grab an offset from the tree
     * @map:	Node map to scan
     * @acc:	Offset accumulator
     * @name:	Netvar name to search for
     * @args:	Remaining netvar names
     *
     * Perform tail recursion with the nodes of the specified branch of the tree passed for map
     * and the offset of that branch added to acc
     */
	template <typename... args_t>
	int get_offset_recursive (map_type &map, int acc, const char *name, args_t... args)
	{
		const auto &node = map[name];
		return get_offset_recursive (node->nodes, acc + node->offset, args...);
	}

	RecvProp *get_prop_recursive (map_type &map, const char *name)
	{
		return map[name]->prop;
	}

	template <typename... args_t>
	RecvProp *get_prop_recursive (map_type &map, const char *name, args_t... args)
	{
		const auto &node = map[name];
		return get_prop_recursive (node->nodes, args...);
	}

public:
	/**
     * get_offset - Get the offset of a netvar given a list of branch names
     * @name:	Top level datatable name
     * @args:	Remaining netvar names
     *
     * Initiate a recursive search down the branch corresponding to the specified datable name
     */
	template <typename... args_t>
	int get_offset (const char *name, args_t... args)
	{
		const auto &node = nodes[name];
		return get_offset_recursive (node->nodes, node->offset, args...);
	}

	template <typename... args_t>
	RecvProp *get_prop (const char *name, args_t... args)
	{
		const auto &node = nodes[name];
		return get_prop_recursive (node->nodes, args...);
	}
};

extern netvar_tree gNetvars;

template <typename T>
class Netvar
{
	DWORD off;

	using sT = typename std::remove_reference<T>::type;

public:
	template <typename... args_t>
	Netvar (args_t... a)
	{
		// just assume these wont be accessed until after netvars has been inited
		// TODO: adding a onetime check here will add very little overhead as this only gets called
		// once per netvar

		off = gNetvars.get_offset (a...);
	}
	template <typename... args_t>
	Netvar (int offset, args_t... a)
	{
		off = gNetvars.get_offset (a...) + offset;
	}

	template <typename B>
	T &GetValue (B base) const
	{
		return GetValue ((PVOID)base);
	}

	T &GetValue (PVOID base) const
	{
		return *reinterpret_cast<sT *> ((DWORD)base + (DWORD)off);
	}

	template <typename B>
	void SetValue (B base, T val) const
	{
		return SetValue ((PVOID)base, val);
	}

	void SetValue (const PVOID base, T val) const
	{
		*reinterpret_cast<sT *> ((DWORD) (base) + ((DWORD) (off))) = val;
	}
	DWORD GetOffset () const
	{
		return off;
	}
};

#define NETVAR(name, type, ...) static Netvar<type> name (__VA_ARGS__)
#define NETVAR_RETURN(type, base, ...) \
	NETVAR (n, type, __VA_ARGS__);     \
	return n.GetValue (base)
#define NETVAR_RETURN_THIS(type, ...) \
	NETVAR (n, type &, __VA_ARGS__);  \
	return n.GetValue (this)

#define NETVAR_OFF(name, type, offset, ...) static Netvar<type> name (offset, __VA_ARGS__)
#define NETVAR_OFF_RETURN(type, base, offset, ...) \
	NETVAR_OFF (n, type, offset, __VA_ARGS__);     \
	return n.GetValue (base)