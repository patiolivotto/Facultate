package Projectiles;

import ProcessingManagers.TimeManager;
import Screen.Screen;
import Shapes.Point;
import Shapes.RectangleShape;

public class SpiderShot extends Projectile {

	public SpiderShot(Screen screen, int ref, TimeManager currentTime) {
		super(screen, ref, currentTime);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void shoot(int dist, Point shooterPosition) {
		// TODO Auto-generated method stub
		int d = currentTime.distanceToTransform(Constants.ProjectileId.SPIDER_SHOT);
		if (d <= dist) {
			//SpiderShot	 round(sin(dist * PI / 2))	 round(cos(dist * PI / 2))
			dist = dist - d;
			ref = ref + ( -(d / 10) - Constants.ProjectileId.SPIDER_SHOT);
			//shooterPosition.translate((int)Math.round(Math.sin(d * Math.PI / 2)), (int)Math.round(Math.cos(d * Math.PI / 2)));
			Point p = new Point(shooterPosition.getX() + (int)Math.round(Math.sin(d * Math.PI / 2))
					, shooterPosition.getY() + (int)Math.round(Math.cos(d * Math.PI / 2)));
			SimpleShell s = new SimpleShell(screen, ref, currentTime);
			s.shoot(dist, p);
		}
		else {
			//shooterPosition.translate((int)Math.round(Math.sin(dist * Math.PI / 2)), (int)Math.round(Math.cos(dist * Math.PI / 2)));
			Point p = new Point(shooterPosition.getX() + (int)Math.round(Math.sin(dist * Math.PI / 2))
					, shooterPosition.getY() + (int)Math.round(Math.cos(dist * Math.PI / 2)));
			ref = ref + ( -(dist / 10) - Constants.ProjectileId.SPIDER_SHOT);
			hitScreenAction(p, ref);
		}
	}

	@Override
	protected void hitScreenAction(Point shooterPosition, int ref) {
		// TODO Auto-generated method stub
		RectangleShape r = new RectangleShape();
		r.draw(screen, ref, shooterPosition);
	}

}
