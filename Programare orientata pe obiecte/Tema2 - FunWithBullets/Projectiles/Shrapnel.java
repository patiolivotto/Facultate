package Projectiles;

import ProcessingManagers.TimeManager;
import Screen.Screen;
import Shapes.Point;
import Shapes.SquareShape;

public class Shrapnel extends Projectile{

	public Shrapnel(Screen screen, int ref, TimeManager currentTime) {
		super(screen, ref, currentTime);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void shoot(int dist, Point shooterPosition) {
		// TODO Auto-generated method stub
		int d = currentTime.distanceToTransform(Constants.ProjectileId.SHRAPNEL);
		if (d <= dist){
			dist = dist - d;
			//shooterPosition.translate((int)Math.round(Math.sin(d * Math.PI / 2)), 0);
			Point p = new Point(shooterPosition.getX() + (int)Math.round(Math.sin(d * Math.PI / 2)), shooterPosition.getY());
			ref = ref + ( -(d / 10) - Constants.ProjectileId.SHRAPNEL);
			SpiderShot s = new SpiderShot(screen, ref, currentTime);
			s.shoot(dist, p);
		}
		else{
			//shooterPosition.translate((int)Math.round(Math.sin(dist * Math.PI / 2)), 0);
			Point p = new Point(shooterPosition.getX() + (int)Math.round(Math.sin(dist * Math.PI / 2)), shooterPosition.getY());
			ref = ref + ( -(dist / 10) - Constants.ProjectileId.SHRAPNEL);
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
