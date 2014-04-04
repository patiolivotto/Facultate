package Shapes;

import Screen.Screen;

public class DotShape extends BasicShape {

	public void draw(Screen screen, int ref, Point centerGrav) {
		// TODO Auto-generated method stub
		screen.drawLineOnScreen(centerGrav, centerGrav, Constants.Symbols.DOT_SYMBOL);
	}
	
}
