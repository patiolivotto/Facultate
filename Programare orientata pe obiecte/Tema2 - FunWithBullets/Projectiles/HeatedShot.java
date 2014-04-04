package Projectiles;

import ProcessingManagers.TimeManager;
import Screen.Screen;
import Shapes.Point;
import Shapes.RhombusShape;

public class HeatedShot extends Projectile{

	public HeatedShot(Screen screen, int ref, TimeManager currentTime) {
		super(screen, ref, currentTime);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void shoot(int dist, Point shooterPosition) {
		// TODO Auto-generated method stub
		int d = currentTime.distanceToTransform(Constants.ProjectileId.HEATED_SHOT);
		if (d <= dist) {
			//HeatedShot	 0	 round(cos(dist * PI / 2))
			dist = dist - d;
			ref = ref + ( -(d / 10) - Constants.ProjectileId.HEATED_SHOT);
			//shooterPosition.translate(0, (int)Math.round(Math.cos(d * Math.PI / 2)));
			Point p = new Point(shooterPosition.getX(), shooterPosition.getY() + (int)Math.round(Math.cos(d * Math.PI / 2)));
			SpiderShot s = new SpiderShot(screen, ref, currentTime);
			s.shoot(dist, p);
		}
		else {
			//shooterPosition.translate(0, (int)Math.round(Math.cos(dist * Math.PI / 2)));
			Point p = new Point(shooterPosition.getX(), shooterPosition.getY() + (int)Math.round(Math.cos(dist * Math.PI / 2)));
			ref = ref + ( -(dist / 10) - Constants.ProjectileId.HEATED_SHOT);
			hitScreenAction(p, ref);
		}
	}

	@Override
	protected void hitScreenAction(Point shooterPosition, int ref) {
		// TODO Auto-generated method stub
		RhombusShape r = new RhombusShape();
		r.draw(screen, ref, shooterPosition);
	}
	

}
