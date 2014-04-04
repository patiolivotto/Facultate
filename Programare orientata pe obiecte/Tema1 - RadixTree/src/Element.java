//Stanciu Catalin 322CA
/**
 * clasa ce implementeaza elemantul unui nod al arborelui
 * @author catalin
 *
 */
public class Element {
	String s;
	int i;
	boolean real;
	/**
	 * constructorul ce initializeaza element al nodului ca fiind nereal
	 * adica nu sirul de caractere continut nu este un cuvant propriuzis ,
	 * ci o parte din acesta
	 */
	Element(){
		real = false;
		s = new String("");
		i = 0;		
	}
	/**
	 *
	 * @return
	 * 		intoarce tipul elementului
	 */
	public boolean isReal(){
		return real;
	}
	/**
	 * functia ce seteaza tipul de element continut in nod
	 * @param tip
	 * 		o valoare booleana ce stabileste tipul elementului
	 */
	public void setReal(boolean tip){
		real = tip;
	}
	/**
	 * functia ce seteaza indexul elementului
	 * @param i
	 * 		Indexul in ordinea inserarii
	 */
	public void seti(int i){
		this.i = i;
	}
	/**
	 * 
	 * @return
	 * 		indexul elementului
	 */
	public int geti(){
		return this.i;
	}
	/**
	 * functia ce seteaza cuvantul obtinut in nod
	 * @param sir
	 * 		cuvantul
	 */
	public void sets(String sir){
		this.s = sir;
	}
	/**
	 * 
	 * @return
	 * 		sirul de caractere din nod
	 */
	public String gets(){
		return this.s;
	}
}
