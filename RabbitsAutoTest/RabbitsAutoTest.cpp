#include "pch.h"
#include "CppUnitTest.h"
#include "..\Rabbits Final Project\Source.cpp"
#include "..\Rabbits Final Project\Door.cpp"
#include "..\Rabbits Final Project\Game.cpp"
#include "..\Rabbits Final Project\GameSystemProgramming.cpp"
#include "..\Rabbits Final Project\Inventory.cpp"
#include "..\Rabbits Final Project\Item.cpp"
#include "..\Rabbits Final Project\OceanMap.cpp"
#include "..\Rabbits Final Project\PLAYER.cpp"
#include "..\Rabbits Final Project\Room.cpp"
#include "..\Rabbits Final Project\SUBMARINE.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RabbitsAutoTest
{
	TEST_CLASS(RabbitsAutoTest)
	{
	public:
		
		TEST_METHOD(VerifyItemCreated)
		{
			std::string str;
			const char* logMsg;
			
			string BATTLE_LANTERN_STRING = "Battle Lantern";
			Item battleLantern;

			str = "*Default item name: " + battleLantern.getItemName() + "\n";
			logMsg = str.c_str();
			Logger::WriteMessage(logMsg);
			Assert::AreNotEqual(BATTLE_LANTERN_STRING, battleLantern.getItemName());
			battleLantern.createItem(BATTLE_LANTERN_STRING, 0, 0, battleLantern);

			str = "*Battle Lantern item name: " + battleLantern.getItemName() + "\n";
			logMsg = str.c_str();
			Logger::WriteMessage(logMsg); 
			Assert::AreEqual(BATTLE_LANTERN_STRING, battleLantern.getItemName());
			   // verify pointer store when item created works correctly
			Assert::AreEqual(BATTLE_LANTERN_STRING, battleLantern.getItemPtr()->getItemName());
		}
		TEST_METHOD(VerifyCanCreateTwoItems)
		{
			std::string str;
			const char* logMsg;

			string STRING1 = "Power Rod";
			string STRING2 = "Hula Hoop";
			Item PowerRod;
			Item HulaHoop;

			PowerRod.createItem(STRING1, 0, 0, HulaHoop);  // Note error in pointer
			HulaHoop.createItem(STRING2, 0, 0, HulaHoop);

			str = "Created Two Items" + PowerRod.getItemName() + " & " + HulaHoop.getItemName() + "\n";
			logMsg = str.c_str();
			Logger::WriteMessage(logMsg);

			Assert::AreEqual(STRING1, PowerRod.getItemName());
			Assert::AreEqual(STRING2, HulaHoop.getItemName());

			// Show can mess up pointers & program won't throw any errors
			Assert::AreEqual(STRING2, PowerRod.getItemPtr()->getItemName());
			Assert::AreEqual(STRING2, HulaHoop.getItemPtr()->getItemName());
		}
	};
}
