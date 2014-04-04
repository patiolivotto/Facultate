import java.util.ArrayList;
import java.util.List;

public class MyHashMapImpl<K, V> implements MyHashMap<K, V> {
	public ArrayList<Bucket<K, V>> b;// "b" este aici lista de bucket-uri.
	int nrb;// nuarul de bucketuri dat la initializare

	/**
	 * setarea numarului de bucket-uri si initilaizarea listei de bucket-uri cu
	 * bucket-uri goale
	 * 
	 * @param nr_buckets
	 * 		nuarul de bucketuri dat
	 */
	public MyHashMapImpl(int nr_buckets) {
		this.b = new ArrayList<Bucket<K, V>>();
		for (int i = 0; i < nr_buckets; i++) {
			b.add(new Bucket<K, V>());
		}
		nrb = nr_buckets;
	}

	@Override
	public V get(K key) {
		// TODO Auto-generated method stub
		int h = Math.abs(key.hashCode()) % nrb;// calculam hash-ul asociat cheii
		for (int i = 0; i < b.get(h).getEntries().size(); i++) {
			// parcurgerea listei de elemente pentru a gasi cheia ceruta si a
			// intoarte valoarea dorita
			if (b.get(h).getEntries().get(i).getKey().equals(key)) {
				return b.get(h).getEntries().get(i).getValue();
			}
		}

		return null;
	}

	@Override
	public V put(K key, V value) {
		// TODO Auto-generated method stub
		int h = Math.abs(key.hashCode()) % nrb;// calculam hash-ul asociat cheii

		for (int i = 0; i < b.get(h).getEntries().size(); i++) {
			// caut daca cheya mai este folosita si inlocuiesc elementul entry .
			if (b.get(h).e.get(i).getKey().equals(key)) {
				V x = b.get(h).getEntries().get(i).getValue();
				remove(key);
				b.get(h).e.add(new Entry<K, V>(key, value));
				return x;
			}
		}

		b.get(h).e.add(new Entry<K, V>(key, value));
		return null;
	}

	@Override
	public V remove(K key) {
		// TODO Auto-generated method stub
		int h = Math.abs(key.hashCode()) % nrb;// calculam hash-ul asociat cheii

		for (int i = 0; i < b.get(h).getEntries().size(); i++) {
			// parcurgerea listei de elemente pentru a gasi cheia ceruta si
			// stergerea acesteiu din lista
			if (b.get(h).getEntries().get(i).getKey().equals(key)) {
				V x = b.get(h).getEntries().get(i).getValue();
				b.get(h).e.remove(i);
				return x;
			}
		}

		return null;
	}

	@Override
	public int size() {
		// TODO Auto-generated method stub
		int nr = 0;
		for (int i = 0; i < nrb; i++) {
			// pentru fiecare bucket numar in lista asociata acestuia numarul de
			// elemente pe care le detine si le insumez
			for (int j = 0; j < b.get(i).getEntries().size(); j++) {
				nr++;
			}
		}
		return nr;// numaru total de elemente
	}

	public static class Entry<K, V> implements MyHashMap.Entry<K, V> {
		K k = null;
		V v = null;

		public Entry(K a, V b) {
			this.k = a;
			this.v = b;
		}

		@Override
		public K getKey() {
			// TODO Auto-generated method stub
			return k;
		}

		@Override
		public V getValue() {
			// TODO Auto-generated method stub
			return v;
		}

	}

	public static class Bucket<K, V> implements MyHashMap.Bucket<K, V> {
		public List<Entry<K, V>> e;

		/**
		 * construcorul ce poate initializa lista de entry-uri
		 */
		public Bucket() {
			e = new ArrayList<Entry<K, V>>();
		}

		/**
		 * construcorul ce adauga un elemant intr-o lista deja existenta
		 * 
		 * @param x
		 *            elementul de tip Entry de introdus in bucket
		 */
		public Bucket(Entry<K, V> x) {
			e.add(x);
		}

		@Override
		public List<? extends MyHashMap.Entry<K, V>> getEntries() {
			// TODO Auto-generated method stub
			return e;
		}

	}

	@Override
	public List<? extends MyHashMap.Bucket<K, V>> getBuckets() {
		// TODO Auto-generated method stub
		return (ArrayList<? extends MyHashMap.Bucket<K, V>>) b;
	}

}
