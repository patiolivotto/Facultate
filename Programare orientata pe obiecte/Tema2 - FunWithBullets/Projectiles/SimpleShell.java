package Projectiles;

import ProcessingManagers.TimeManager;
import Screen.Screen;
import Shapes.*;

public class SimpleShell extends Projectile {

	public SimpleShell(Screen screen, int ref, TimeManager currentTime) {
		super(screen, ref, currentTime);
		// TODO Auto-generated constructor stub
		
	}

	@Override
	public void shoot(int dist, Point shooterPosition) {
		// TODO Auto-generated method stub
		//ref = ref + ( -(dist / 10) - Constants.ProjectileId.SIMPLE_SHELL);
		hitScreenAction(shooterPosition, ref);
	}

	@Override
	protected void hitScreenAction(Point shooterPosition, int ref) {
		// TODO Auto-generated method stub
		DotShape d = new DotShape();
		d.draw(screen, ref, shooterPosition);
	}

}
