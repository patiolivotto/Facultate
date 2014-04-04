
public class Student {
	public String nume;
	public int varsta;
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((nume == null) ? 0 : nume.hashCode());
		result = prime * result + varsta;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Student other = (Student) obj;
		if (nume == null) {
			if (other.nume != null)
				return false;
		} else if (!nume.equals(other.nume))
			return false;
		if (varsta != other.varsta)
			return false;
		return true;
	}
	
	
}
