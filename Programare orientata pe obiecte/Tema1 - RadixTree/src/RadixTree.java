//Stanciu Catalin 322CA

import java.util.ArrayList;

	/**
	 * clasa ce implementeaza arborele
	 * @author catalin
	 *
	 */
public class RadixTree {
	RTNode first;
	/**
	 * constructorul pentru clasa arborlui in care 
	 * este initializata radacina arborelui 
	 */
	public RadixTree(){
		first = new RTNode();
	}
	/**
	 * metoda de inserare a unui cuvant impreuna cu numarul corespunzator la adaugare
	 * @param p
	 * 		reprezinta radacina de unde se incepe adaugare elementelor in arbore
	 * @param sir
	 * 		sirul de caractere ce urmeaza sa fie inserat
	 * @param index
	 * 		numarul ce corespunde inserarii
	 */
	public void insert(RTNode p , String sir , int index){
		int x = p.nomc(sir);
		
		if (p.e.gets().equals("") || x == 0 || (x < sir.length() && x >= p.e.gets().length())) {
            boolean ok = false;
            String aux = sir.substring(x, sir.length());
            for (RTNode c : p.getNode()) {
                if (c.e.gets().startsWith(aux.charAt(0) + "")) {
                    ok = true;
                    insert(c, aux, index);
                    break;
                }
            }
            //inserarea ca si urmas al nodului curent
            if (ok == false) {
                RTNode n = new RTNode();
                n.e.sets(aux);
                n.e.setReal(true);
                n.e.seti(index);
                p.getNode().add(n);
            }
        }
		//inserarea in cazul duplicatelor
		else if ( x == sir.length() && x == p.e.gets().length()) {
            if (p.e.isReal()) {
                RTNode p0 = new RTNode();
                p0.e.sets(" ");
                p0.e.setReal(true);
                p0.e.seti(index);
                p.e.setReal(false);
                RTNode p01 = new RTNode();
                p01.e.sets(" ");
                p01.e.setReal(true);
                p01.e.seti(p.e.geti());
                p.getNode().add(p01);
                p.getNode().add(p0);
            }
            else {
            	RTNode p01 = new RTNode();
                p01.e.sets(" ");
                p01.e.setReal(true);
                p01.e.seti(index);
                p.getNode().add(p01);
            }     
        }
        //inserarea prin despartirea cuvantului
		else if (x > 0 && x < p.e.gets().length()) {
            RTNode p1 = new RTNode();
            p1.e.sets(p.e.gets().substring(x, p.e.gets().length()));
            p1.e.setReal(p.e.isReal());
            p1.e.seti(p.e.geti());
            p1.setNode(p.getNode());
            p.e.sets(sir.substring(0, x));
            p.e.setReal(false);
            p.setNode(new ArrayList<RTNode>());
            p.getNode().add(p1);
            if(x < sir.length()) {
	            RTNode p2 = new RTNode();
	            p2.e.sets(sir.substring(x, sir.length()));
	            p2.e.setReal(true);
	            p2.e.seti(index);
	            p.getNode().add(p2);
            } else {
            	p.e.seti(index);
                p.e.setReal(false);
                RTNode p01 = new RTNode();
                p01.e.sets(" ");
                p01.e.setReal(true);
                p01.e.seti(index);
                p.getNode().add(p01);
            }
        } 
        else {
            RTNode p3 = new RTNode();
            p3.e.sets(p.e.gets().substring(x, p.e.gets().length()));
            p3.setNode(p.getNode());
            p3.e.setReal(p.e.isReal());
            p3.e.seti(p.e.geti());
            p.e.sets(sir);
            p.e.setReal(true);
            p.e.seti(index);
            p.getNode().add(p3);
        }
	}
	/**
	 * metoda ce numara cate noduri cu indecsi contine nodu trimis ca radacina prin `r`
	 * @param r
	 * 		radacina
	 * @param l
	 * 		lista de indecsi goala initial
	 * @param o
	 * 		o valoare ce ne spune cand sa returnam lista cu indecsi
	 * @return
	 * 		lista de indecsi continuti de toate nodurile si subnodurile
	 */
	public ArrayList<Integer> count(RTNode r,ArrayList<Integer> l, boolean o) {  
		boolean ok = o;
		for (RTNode x : r.getNode() ){
			if (x.e.isReal()){
				l.add(x.e.geti());
			}
			count(x,l,true);
		}
		if (ok == false){
			return l;
		}
		return null;
	}
	/**
	 * metoda ce cuta prefixul in  arbore si afiseaza lista de indecsi
	 * @param p
	 * 		radacina de la care se porneste cautarea in arbore
	 * @param prefix
	 * 		sirul de caractere ce va fi cautat ca si prefix
	 * 	
	 */
	public void findPrefix(RTNode p , String prefix){
		for (RTNode r : p.getNode()){
			int x = r.nomc(prefix);
			if ((x == prefix.length() && x != 0 && !prefix.equals("") )){ 
				
				ArrayList<Integer> u = new ArrayList<Integer>();
				ArrayList<Integer> l = count(r, u, false);
				//afisare
				if (l.size() == 0) {
					System.out.print("1");
					System.out.print(" " + r.e.geti());
					System.out.println();
					return;
				}
				System.out.print(l.size());
				for (int nr : l){
					System.out.print(" " + nr);
				}
				System.out.println();
				return ;
			}
			if (x < prefix.length() && x == r.e.gets().length()){
				String sub = prefix.substring(x, prefix.length());
				findPrefix(r, sub);
			}
		}	
	}
}
