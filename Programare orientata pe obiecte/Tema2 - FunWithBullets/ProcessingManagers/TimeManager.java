package ProcessingManagers;

/**
 * Time object
 */
public class TimeManager {
	private int h,m,s;

	// TODO => implement the body of the class (set class fields, make ways 
	// 			for other classes to work with a TimeManager object)
	public TimeManager(int h,int m, int s){
		this.h = h;
		this.m = m;
		this.s = s;
	}
	
	public int geth(){
		return h;
	}
	
	public int getm(){
		return m;
	}
	
	public int gets(){
		return s;
	}
	
	public int distanceToTransform(int id ){
		//id = 42 + (id * id * ora + id * minutul + secunda) % 42
		int dist = 42 + ( id * id * h + id * m + s ) % 42;
		return dist;
	}
	
}