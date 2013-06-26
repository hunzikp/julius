#include "Advisors_private.h"

static void drawFestivalBackground();

static void buttonHoldFestival(int param1, int param2);

static CustomButton holdFestivalButtons[1] = {
	{102, 280, 402, 300, buttonHoldFestival, Widget_Button_doNothing, 1, 0, 0},
};

static int focusButtonId;

void UI_Advisor_Entertainment_drawBackground()
{
	// TODO calculateGodHappiness
	// TODO gatherEntertainmentInfo

	int baseOffsetX = Data_Screen.offset640x480.x;
	int baseOffsetY = Data_Screen.offset640x480.y;

	Widget_Panel_drawOuterPanel(baseOffsetX, baseOffsetY, 40, 23);
	Graphics_drawImage(GraphicId(ID_Graphic_AdvisorIcons) + Advisor_Entertainment + 1,
		baseOffsetX + 10, baseOffsetY + 10);

	Widget_GameText_draw(58, 0, baseOffsetX + 60, baseOffsetY + 12, Font_LargeBlack, 0);

	Widget_GameText_draw(58, 1, baseOffsetX + 180, baseOffsetY + 46, Font_SmallPlain, 0);
	Widget_GameText_draw(58, 2, baseOffsetX + 260, baseOffsetY + 46, Font_SmallPlain, 0);
	Widget_GameText_draw(58, 3, baseOffsetX + 340, baseOffsetY + 46, Font_SmallPlain, 0);
	Widget_GameText_draw(58, 4, baseOffsetX + 480, baseOffsetY + 46, Font_SmallPlain, 0);

	int width;
	Widget_Panel_drawInnerPanel(baseOffsetX + 32, baseOffsetY + 60, 36, 5);

	// theaters
	Widget_GameText_drawNumberWithDescription(8, 34, Data_CityInfo_Buildings.theater.total,
		baseOffsetX + 40, baseOffsetY + 64, Font_NormalWhite, 0
	);
	Widget_Text_drawNumberCentered(Data_CityInfo_Buildings.theater.working, '@', " ",
		baseOffsetX + 150, baseOffsetY + 64, 100, Font_NormalWhite, 0
	);
	Widget_Text_drawNumberCentered(Data_CityInfo.entertainmentTheaterShows, '@', " ",
		baseOffsetX + 230, baseOffsetY + 64, 100, Font_NormalWhite, 0
	);
	width = Widget_Text_drawNumber(500 * Data_CityInfo_Buildings.theater.working, '@', " ",
		baseOffsetX + 340, baseOffsetY + 64, Font_NormalWhite, 0
	);
	Widget_GameText_draw(58, 5, baseOffsetX + 340 + width, baseOffsetY + 64, Font_NormalWhite, 0);
	if (Data_CityInfo_CultureCoverage.theater == 0) {
		Widget_GameText_drawCentered(57, 10, baseOffsetX + 470, baseOffsetY + 64, 100, Font_NormalWhite, 0);
	} else if (Data_CityInfo_CultureCoverage.theater < 100) {
		Widget_GameText_drawCentered(57, 11 + Data_CityInfo_CultureCoverage.theater / 10,
			baseOffsetX + 470, baseOffsetY + 64, 100, Font_NormalWhite, 0
		);
	} else {
		Widget_GameText_drawCentered(57, 21, baseOffsetX + 470, baseOffsetY + 64, 100, Font_NormalWhite, 0);
	}

	// amphitheaters
	Widget_GameText_drawNumberWithDescription(8, 36, Data_CityInfo_Buildings.amphitheater.total,
		baseOffsetX + 40, baseOffsetY + 84, Font_NormalWhite, 0
	);
	Widget_Text_drawNumberCentered(Data_CityInfo_Buildings.amphitheater.working, '@', " ",
		baseOffsetX + 150, baseOffsetY + 84, 100, Font_NormalWhite, 0
	);
	Widget_Text_drawNumberCentered(Data_CityInfo.entertainmentAmphitheaterShows, '@', " ",
		baseOffsetX + 230, baseOffsetY + 84, 100, Font_NormalWhite, 0
	);
	width = Widget_Text_drawNumber(800 * Data_CityInfo_Buildings.amphitheater.working, '@', " ",
		baseOffsetX + 340, baseOffsetY + 84, Font_NormalWhite, 0
	);
	Widget_GameText_draw(58, 5, baseOffsetX + 340 + width, baseOffsetY + 84, Font_NormalWhite, 0);
	if (Data_CityInfo_CultureCoverage.amphitheater == 0) {
		Widget_GameText_drawCentered(57, 10, baseOffsetX + 470, baseOffsetY + 84, 100, Font_NormalWhite, 0);
	} else if (Data_CityInfo_CultureCoverage.amphitheater < 100) {
		Widget_GameText_drawCentered(57, 11 + Data_CityInfo_CultureCoverage.amphitheater / 10,
			baseOffsetX + 470, baseOffsetY + 84, 100, Font_NormalWhite, 0
		);
	} else {
		Widget_GameText_drawCentered(57, 21, baseOffsetX + 470, baseOffsetY + 84, 100, Font_NormalWhite, 0);
	}

	// colosseums
	Widget_GameText_drawNumberWithDescription(8, 38, Data_CityInfo_Buildings.colosseum.total,
		baseOffsetX + 40, baseOffsetY + 104, Font_NormalWhite, 0
	);
	Widget_Text_drawNumberCentered(Data_CityInfo_Buildings.colosseum.working, '@', " ",
		baseOffsetX + 150, baseOffsetY + 104, 100, Font_NormalWhite, 0
	);
	Widget_Text_drawNumberCentered(Data_CityInfo.entertainmentColosseumShows, '@', " ",
		baseOffsetX + 230, baseOffsetY + 104, 100, Font_NormalWhite, 0
	);
	width = Widget_Text_drawNumber(1500 * Data_CityInfo_Buildings.colosseum.working, '@', " ",
		baseOffsetX + 340, baseOffsetY + 104, Font_NormalWhite, 0
	);
	Widget_GameText_draw(58, 5, baseOffsetX + 340 + width, baseOffsetY + 104, Font_NormalWhite, 0);
	if (Data_CityInfo_CultureCoverage.colosseum == 0) {
		Widget_GameText_drawCentered(57, 10, baseOffsetX + 470, baseOffsetY + 104, 100, Font_NormalWhite, 0);
	} else if (Data_CityInfo_CultureCoverage.colosseum < 100) {
		Widget_GameText_drawCentered(57, 11 + Data_CityInfo_CultureCoverage.colosseum / 10,
			baseOffsetX + 470, baseOffsetY + 104, 100, Font_NormalWhite, 0
		);
	} else {
		Widget_GameText_drawCentered(57, 21, baseOffsetX + 470, baseOffsetY + 104, 100, Font_NormalWhite, 0);
	}

	// hippodromes
	Widget_GameText_drawNumberWithDescription(8, 40, Data_CityInfo_Buildings.hippodrome.total,
		baseOffsetX + 40, baseOffsetY + 123, Font_NormalWhite, 0
	);
	Widget_Text_drawNumberCentered(Data_CityInfo_Buildings.hippodrome.working, '@', " ",
		baseOffsetX + 150, baseOffsetY + 123, 100, Font_NormalWhite, 0
	);
	Widget_Text_drawNumberCentered(Data_CityInfo.entertainmentHippodromeShows, '@', " ",
		baseOffsetX + 230, baseOffsetY + 123, 100, Font_NormalWhite, 0
	);
	Widget_GameText_draw(58, 6, baseOffsetX + 360, baseOffsetY + 123, Font_NormalWhite, 0);
	if (Data_CityInfo_CultureCoverage.hippodrome == 0) {
		Widget_GameText_drawCentered(57, 10, baseOffsetX + 470, baseOffsetY + 123, 100, Font_NormalWhite, 0);
	} else {
		Widget_GameText_drawCentered(57, 21, baseOffsetX + 470, baseOffsetY + 123, 100, Font_NormalWhite, 0);
	}

	int adviceId;

	// TODO ...
	drawFestivalBackground();
}
//----- (00516930) --------------------------------------------------------
/*
void __cdecl fun_drawEntertainmentAdvisor()
{
      if ( cityinfo_evolveEntertainmentRequired[4517 * ciid] <= cityinfo_evolveMoreEntertainmentRequired[4517 * ciid] )
      {
        if ( cityinfo_evolveMoreEntertainmentRequired[4517 * ciid] )
        {
          if ( cityinfo_entertainmentNeedingShowsMost[4517 * ciid] )
          {
            switch ( cityinfo_entertainmentNeedingShowsMost[4517 * ciid] )
            {
              case 1:
                textNumber = 4;
                break;
              case 2:
                textNumber = 5;
                break;
              case 3:
                textNumber = 6;
                break;
              case 4:
                textNumber = 7;
                break;
            }
          }
          else
          {
            textNumber = 2;
          }
        }
        else
        {
          if ( cityinfo_entertainment_needsMet[4517 * ciid] )
            textNumber = 1;
          else
            textNumber = 0;
        }
      }
      else
      {
        textNumber = 3;
      }
      j_fun_drawGameTextWrapped(58, textNumber + 7, dialog_x + 60, dialog_y + 148, 512, graphic_font + 134, 0);
      j_fun_drawEntertainmentAdvisorFestivals();
}
*/

static void drawFestivalBackground()
{
	int baseOffsetX = Data_Screen.offset640x480.x;
	int baseOffsetY = Data_Screen.offset640x480.y;

	Widget_Panel_drawInnerPanel(baseOffsetX + 48, baseOffsetY + 252, 34, 6);
	Graphics_drawImage(GraphicId(ID_Graphic_PanelWindows) + 15,
		baseOffsetX + 460, baseOffsetY + 255);
	int width = Widget_GameText_drawNumberWithDescription(
		8, 4, Data_CityInfo.monthsSinceFestival,
		baseOffsetX + 112, baseOffsetY + 260, Font_NormalWhite, 0
	);
	Widget_GameText_draw(58, 15, baseOffsetX + 112 + width, baseOffsetY + 260, Font_NormalWhite, 0);
	if (Data_CityInfo.plannedFestivalSize) {
		Widget_GameText_drawCentered(58, 34,
			baseOffsetX + 102, baseOffsetY + 284,
			300, Font_NormalWhite, 0);
	} else {
		Widget_GameText_drawCentered(58, 16,
			baseOffsetX + 102, baseOffsetY + 284,
			300, Font_NormalWhite, 0);
	}
	int adviceId;
	if (Data_CityInfo.monthsSinceFestival <= 1) {
		adviceId = 0;
	} else if (Data_CityInfo.monthsSinceFestival <= 6) {
		adviceId = 1;
	} else if (Data_CityInfo.monthsSinceFestival <= 12) {
		adviceId = 2;
	} else if (Data_CityInfo.monthsSinceFestival <= 18) {
		adviceId = 3;
	} else if (Data_CityInfo.monthsSinceFestival <= 24) {
		adviceId = 4;
	} else if (Data_CityInfo.monthsSinceFestival <= 30) {
		adviceId = 5;
	} else {
		adviceId = 6;
	}
	Widget_GameText_drawMultiline(58, 18 + adviceId,
		baseOffsetX + 56, baseOffsetY + 305,
		380, Font_NormalWhite, 0);
}


void UI_Advisor_Entertainment_drawForeground()
{
	if (!Data_CityInfo.plannedFestivalSize) {
		Widget_Panel_drawButtonBorder(
			Data_Screen.offset640x480.x + 102, Data_Screen.offset640x480.y + 280,
			300, 20, focusButtonId == 1);
	}
}

void UI_Advisor_Entertainment_handleMouse()
{
	Widget_Button_handleCustomButtons(
		Data_Screen.offset640x480.x, Data_Screen.offset640x480.y,
		holdFestivalButtons, 1, &focusButtonId);
}

void buttonHoldFestival(int param1, int param2)
{
	// TODO
}