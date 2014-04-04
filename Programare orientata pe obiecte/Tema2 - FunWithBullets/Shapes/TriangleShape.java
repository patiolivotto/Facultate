package Shapes;

import Screen.Screen;

public class TriangleShape extends BasicShape{

	@Override
	public void draw(Screen screen, int ref, Point centerGrav) {
		// TODO Auto-generated method stub
		Point p1 = new Point(centerGrav.getX(), centerGrav.getY() - (2 * ref));
		Point p2 = new Point(centerGrav.getX() + ref, centerGrav.getY() + ref);
		Point p3 = new Point(centerGrav.getX() - ref, centerGrav.getY() + ref);
		screen.drawLineOnScreen(p1 , p2, Constants.Symbols.TRIANGLE_SYMBOL);
		screen.drawLineOnScreen(p2 , p3, Constants.Symbols.TRIANGLE_SYMBOL);
		screen.drawLineOnScreen(p3 , p1, Constants.Symbols.TRIANGLE_SYMBOL);
		//System.out.println("p"+p1+p2+p3+centerGrav+ref);
	}
	

}
