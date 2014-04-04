package Screen;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import Constants.Symbols;
import ProcessingManagers.DrawManager;
import Shapes.Point;

/**
 * Class that represents the screen to be projected on
 */
public class Screen {
	private char[][] matrix;
	
	/**
	 * Builds the necessary data of the screen
	 * 
	 * @param sizeX	screen size on X axis
	 * @param sizeY	screen size on Y axis
	 */
	public Screen(int sizeX, int sizeY) {
		// TODO
		this.matrix = new char[sizeX][sizeY];
		for (int i = 0; i < sizeX; i++){
			for (int j = 0;j < sizeY; j++){
				this.matrix[i][j] = Symbols.SCREEN_SYMBOL;
			}
		}
		
	}
	
	/**
	 * Draws a line on the screen between the given points
	 * 
	 * @param startPoint	the first end of the line
	 * @param endPoint		the second end of the line
	 * @param symbol		the symbol the line is drawn with
	 */
	public void drawLineOnScreen(Point startPoint, Point endPoint, 
			char symbol) {
		// TODO
		// Hint: Use DrawManager
		DrawManager.drawLine(matrix, startPoint, endPoint, symbol);
	}
	
	/**
	 * Draws multiple lines, each defined by startPoints[index] and
	 * endPoints[index] 
	 * 
	 * @param startPoints	array of first ends of the lines
	 * @param endPoints		array of second ends of the lines
	 * @param symbol		the symbol with which ALL lines are drawn
	 */
	public void drawMultipleLinesOnScreen(Point[] startPoints,
			Point[] endPoints, char symbol) {
		// TODO
		for (int i = 0; i < startPoints.length; i++){
			drawLineOnScreen(startPoints[i], endPoints[i], symbol);
		}		 
	}
	public void printToFile(String name, int x, int y){
		File g = new File(name);
		try {
			g.createNewFile();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		FileWriter writer;
		try {
			writer = new FileWriter(g);
			for (int i = 0; i < x;i++){
				for (int j = 0;j < y;j++){
					writer.write(matrix[i][j]); 
				}
				writer.write("\n");
			}
			writer.write("\n");
		    writer.flush();
		    writer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
}
