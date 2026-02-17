#include "../../commandmanager.h"

namespace ResetActor {
	void Install() {
#define cmd                                                                                     \
					const std::vector<std::string> &args, RE::Script *a_script, RE::ScriptCompiler *a_compiler, \
						RE::COMPILER_NAME a_name, RE::TESObjectREFR *a_targetRef
#define PRINT RE::ConsoleLog::GetSingleton()->Print

		CommandManager::Register("ResetActor", [](cmd) {
			if (a_targetRef && a_targetRef->Is(RE::FormType::ActorCharacter)) {
				auto&& actor = a_targetRef->As<RE::Actor>();

				REL::Relocation<void(*)(RE::Actor*, bool bResetInv)> reset{ RELOCATION_ID(36331, 37321) };
				reset(actor, false);
				PRINT("%s reset", actor->GetDisplayFullName());
			}
		});
	}
}