package Projectiles;

import ProcessingManagers.TimeManager;
import Screen.Screen;
import Shapes.Point;
import Shapes.TriangleShape;

public class ChainShot extends Projectile{

	public ChainShot(Screen screen, int ref, TimeManager currentTime) {
		super(screen, ref, currentTime);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void shoot(int dist, Point shooterPosition) {
		// TODO Auto-generated method stub
		int d = currentTime.distanceToTransform(Constants.ProjectileId.CHAIN_SHOT);
		if (d <= dist){
			dist = dist - d;
			//shooterPosition.translate(0, -d);
			Point p = new Point(shooterPosition.getX(), shooterPosition.getY() - d);
			ref = ref + ( -(d / 10) - Constants.ProjectileId.CHAIN_SHOT);
			Shrapnel s = new Shrapnel(screen, ref, currentTime);
			s.shoot(dist, p);
		}
		else{
			//shooterPosition.translate(0, -dist);
			Point p = new Point(shooterPosition.getX(), shooterPosition.getY() - dist);
			ref = ref + ( -(dist / 10) - Constants.ProjectileId.CHAIN_SHOT);
			hitScreenAction(p, ref);
		}
	}

	@Override
	protected void hitScreenAction(Point shooterPosition, int ref) {
		// TODO Auto-generated method stub
		TriangleShape t = new TriangleShape();
		t.draw(screen, ref, shooterPosition);
	}

}
