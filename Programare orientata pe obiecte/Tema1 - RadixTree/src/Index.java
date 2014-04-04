//Stanciu Catalin 322CA

/**
 * This execution entry point class handles the parsing, indexing and lookup of words in a text.
 */
public class Index {

	/**
	 * Execution entry point.
	 *
	 * @param args two strings representing the name of the file that contains the text to index,
	 * and the name of the file containing words to lookup in the text.
	 */
	public static void main(String[] args) {
		if (args.length != 2) {
			System.err.println("Usage: java -cp <classpath> Index <text file> <word file>");
			System.exit(1);
		}

		// TODO: replace with homework implementation:

		String word;

		FileParser textFile = new FileParser(args[0]);
		textFile.open();
		/*
		 * am initializat arborele `RT` si am initializat cu -1 pe nr
		 *  pentru numararea aparitiei la inserare
		 */
		RadixTree RT = new RadixTree();
		int nr = -1;
		while ((word = textFile.getNextWord()) != null) {
			/*
			 * am incrementat pe nr si am inserat fiecare cuvant 
			 * citit din fisier folosind metoda insert a arborelui
			 */
			nr++;
			RT.insert(RT.first, word, nr);
		}
		
		textFile.close();

		FileParser prefixFile = new FileParser(args[1]);
		prefixFile.open();
		
		while ((word = prefixFile.getNextWord()) != null) {
			
			/*
			 * pentru fiecare prefix citit din fisier l-am acutat in arbore 
			 * si am afisat pozitiile in care acesta poate fi intalnit
			 */
			RT.findPrefix(RT.first, word);
			
		}
		prefixFile.close();
	}
}