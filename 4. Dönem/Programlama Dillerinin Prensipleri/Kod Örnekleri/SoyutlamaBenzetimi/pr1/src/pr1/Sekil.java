package pr1;

import java.util.Date;

public abstract class Sekil {
	private String renk;
	private Date olusturulmaTarihi;
	public Sekil(String renk) {
		this.renk = renk;
		olusturulmaTarihi = new Date();
	}
	public void setRenkk(String renk) {
		this.renk = renk;
	}
	public abstract double alan();		//sınıf abstract içeriyorsa kendisi de abstract olmak zorundadır
	public abstract double cevre();
	@Override
	public String toString() {
		String cikti= "Tarih: " + olusturulmaTarihi.toString() + "\n";
		cikti+= "Renk: " + renk + "\n";
		cikti+= "Alan: " + alan() + "\n";
		cikti+= "Cevre: " + cevre() + "\n"; 	//göcvedsi olmasa bile varmış gibi çağırabilir
		return cikti;
	}
}
