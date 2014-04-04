//Stanciu Catalin 322CA

import java.util.ArrayList;
import java.util.List;
/**
 * clasa ce implementeaza nodurile arborelui.
 * @author Stanciu Catalin - 322CA
 *
 */
public class RTNode {
	Element e ;//elementul continut de fiecare nod
	List<RTNode> nod ; 
	/**
	 * constructorul ce initializeaza nodul si elementul acestuia.
	 */
	RTNode(){
		e = new Element();
		nod = new ArrayList<RTNode>();
	}
	/**
	 *metoda ce intoarce lista continuta de nodul curent 
	 * @return
	 */
	public List<RTNode> getNode(){
		return nod;
	}
	/**
	 * metoda ce seteaza urmatorul urmasul nodului curent
	 * @param p
	 */
	public void setNode(List<RTNode> p){
		this.nod = p;
	}
	/**
	 * metoda calculeaza numarul de caractere ce coincid intre
	 *  un sir de caractere si valoarea elementului din nodul curent
	 * @param sir
	 * 		sirul de comparat
	 * @return
	 * 		numarul de caractere ce coincid
	 */
	public int nomc(String sir) {
		int x = 0;
		while (sir.length() > x && e.gets().length() > x && sir.charAt(x) == e.gets().charAt(x) ){
			x++;
		}
		return x;
	}
	

}
