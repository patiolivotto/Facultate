package Projectiles;

import ProcessingManagers.TimeManager;
import Screen.Screen;
import Shapes.Point;
import Shapes.SquareShape;

public class Carcass extends Projectile{

	public Carcass(Screen screen, int ref, TimeManager currentTime) {
		super(screen, ref, currentTime);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void shoot(int dist, Point shooterPosition) {
		// TODO Auto-generated method stub
		int d = currentTime.distanceToTransform(Constants.ProjectileId.CARCASS);
		if (d <= dist){
			dist = dist - d;
			//shooterPosition.translate(0, d);
			Point p = new Point(shooterPosition.getX(), shooterPosition.getY() + d);
			ref = ref + ( -(d / 10) - Constants.ProjectileId.CARCASS);
			HeatedShot s = new HeatedShot(screen, ref, currentTime);
			s.shoot(dist, p);
		}
		else{
			//shooterPosition.translate(0, dist);
			Point p = new Point(shooterPosition.getX(), shooterPosition.getY() + dist);
			ref = ref + ( -(dist / 10) - Constants.ProjectileId.CARCASS);
			hitScreenAction(p, ref);
		}
	}

	@Override
	protected void hitScreenAction(Point shooterPosition, int ref) {
		// TODO Auto-generated method stub
		SquareShape s = new SquareShape();
		s.draw(screen, ref, shooterPosition);
	}

}
