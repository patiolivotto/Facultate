package Projectiles;

import ProcessingManagers.TimeManager;
import Screen.Screen;
import Shapes.Point;
import Shapes.RectangleShape;

public class CanisterShot extends Projectile {

	public CanisterShot(Screen screen, int ref, TimeManager currentTime) {
		super(screen, ref, currentTime);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void shoot(int dist, Point shooterPosition) {
		// TODO Auto-generated method stub
		int d = currentTime.distanceToTransform(Constants.ProjectileId.CANNISTER_SHOT);
		if (d <= dist){
			dist = dist - d ;
			//shooterPosition.translate(-d, 0);
			Point p = new Point(shooterPosition.getX() - d, shooterPosition.getY());			
			ref = ref + ( -(d / 10) - Constants.ProjectileId.CANNISTER_SHOT);
			HeatedShot s = new HeatedShot(screen, ref, currentTime);
			s.shoot(dist, p);
		}
		else{
			//shooterPosition.translate(-dist, 0);
			Point p = new Point(shooterPosition.getX() - dist, shooterPosition.getY());
			ref = ref + ( -(dist / 10) -Constants.ProjectileId.CANNISTER_SHOT);
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
