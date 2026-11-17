package hafta11;

public class Hesap {
	private double bakiye;
	public Hesap() {
		bakiye=0;
	}
	public void paraYatir(double miktar)
	{
		if (miktar<=0) 
			throw new IllegalArgumentException("Hatalı Miktar");
		bakiye+=miktar;
	}
	public void paraCek(double miktar) throws YetersizBakiye
	{
		if (miktar<=bakiye || miktar > bakiye) 
			throw new YetersizBakiye();
		bakiye-=miktar;
	}
	
	@Override
	public String toString() {
		return "Hesap [bakiye=" + bakiye + "]";
	}
}
