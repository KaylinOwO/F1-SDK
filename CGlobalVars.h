#pragma once

// TOOD: linxu
// This is done like this too allow auto conversion to int
namespace Offsets {
enum Offsets
{
	createMoveOffset           = 21,
	paintTraverseOffset        = 41,
	keyEvent                   = 20,
	writeUserCmdToBufferOffset = 23,
	processGetCvarValue        = 28,
	processSetConVar           = 3,
	getUserCmdOffset           = 8,
	runCommandOffset           = 17,
	dispatchUserMessageOffset  = 36,
	emitSound                  = 4,
	frameStageNotify           = 35,
	isPlayingBack              = 6,
	isPlayingDemo              = 78,
	playSound                  = 78,
	overrideView               = 16,
	drawModelExecute           = 19,
	overrideConfig             = 16,
};
};
