import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.util.StringTokenizer;

import ProcessingManagers.TimeManager;
import Projectiles.CanisterShot;
import Projectiles.Carcass;
import Projectiles.ChainShot;
import Projectiles.HeatedShot;
import Projectiles.Shrapnel;
import Projectiles.SimpleShell;
import Projectiles.SpiderShot;
import Projectiles.TriGrapeShot;
import Screen.Screen;
import Shapes.Point;

public class Main {
	public static void readLineAndHitTheScreen(Scanner scan, Screen screen){
		String s = scan.nextLine();
		StringTokenizer tok = new StringTokenizer(s);
		String projectiletype = tok.nextToken(" ").trim();
		int ref = Integer.parseInt(tok.nextToken(" ").trim());
		int hh = Integer.parseInt(tok.nextToken(":").trim());
		int mm = Integer.parseInt(tok.nextToken(":").trim());
		int ss = Integer.parseInt(tok.nextToken(" ").substring(1).trim());
		int dist = Integer.parseInt(tok.nextToken(" ").trim());
		int posx = Integer.parseInt(tok.nextToken(" ").trim());
		int posy = Integer.parseInt(tok.nextToken(" ").trim());
		
		TimeManager currentTime = new TimeManager(hh, mm, ss);
		Point shooterPosition = new Point(posx, posy);
		
		if (projectiletype.equals(Constants.ProjectileNames.CANNISTER_SHOT)){
			CanisterShot p = new CanisterShot(screen, ref, currentTime);
			p.shoot(dist, shooterPosition);
		}
		if (projectiletype.equals(Constants.ProjectileNames.CARCASS)){
			Carcass p = new Carcass(screen, ref, currentTime);
			p.shoot(dist, shooterPosition);
		}
		if (projectiletype.equals(Constants.ProjectileNames.CHAIN_SHOT)){
			ChainShot p = new ChainShot(screen, ref, currentTime);
			p.shoot(dist, shooterPosition);
		}
		if (projectiletype.equals(Constants.ProjectileNames.HEATED_SHOT)){
			HeatedShot p = new HeatedShot(screen, ref, currentTime);
			p.shoot(dist, shooterPosition);
		}
		if (projectiletype.equals(Constants.ProjectileNames.SHRAPNEL)){
			Shrapnel p = new Shrapnel(screen, ref, currentTime);
			p.shoot(dist, shooterPosition);
		}
		if (projectiletype.equals(Constants.ProjectileNames.SIMPLE_SHELL)){
			SimpleShell p = new SimpleShell(screen, ref, currentTime);
			p.shoot(dist, shooterPosition);
		}
		if (projectiletype.equals(Constants.ProjectileNames.SPIDER_SHOT)){
			SpiderShot p = new SpiderShot(screen, ref, currentTime);
			p.shoot(dist, shooterPosition);
		}
		if (projectiletype.equals(Constants.ProjectileNames.TRI_GRAPE_SHOT)){
			TriGrapeShot p = new TriGrapeShot(screen, ref, currentTime);
			p.shoot(dist, shooterPosition);
		}
		
		//System.out.print(projectiletype+" "+ref+" "+hh+" "+mm+" "+ss+" "+dist+" "+posx+" "+posy+" "+"\n");
		
	}
	public static void main(String[] args) {
			InputStream inStream = null;
			//BufferedInputStream bis = null;
	      
			try{
	         // open input stream test.txt for reading purpose.
	         inStream = new FileInputStream(args[0]);

	        Scanner scan = new Scanner(inStream);
	        String s1 = scan.nextLine();
	        String s2 = scan.nextLine();
	        StringTokenizer tok = new StringTokenizer(s1);
	        int sizex = Integer.parseInt(tok.nextToken(" "));
	        int sizey = Integer.parseInt(tok.nextToken(" "));
	        StringTokenizer tok1 = new StringTokenizer(s2);
	        int n = Integer.parseInt(tok1.nextToken(" "));
	        System.out.println(sizex+" "+sizey+" " +n);
	        //initializare ecran
	        Screen screen = new Screen(sizex,sizey);
	        
	        for (int i = 0; i < n; i++){
	        	readLineAndHitTheScreen(scan, screen);
	        }
	        inStream.close();
	        screen.printToFile(args[0]+"_out", sizex, sizey);
	      }catch(Exception e){
	         // if any I/O error occurs
	         e.printStackTrace();
	      }finally{		
	         // releases any system resources associated with the stream
	        // if(inStream!=null)
	         //   inStream.close();
	        // if(bis!=null)
	          //  bis.close();
	      }
		
		
	}
}
