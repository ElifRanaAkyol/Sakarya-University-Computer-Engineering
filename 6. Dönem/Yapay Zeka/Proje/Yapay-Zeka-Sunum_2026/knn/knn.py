from sklearn.neighbors import KNeighborsClassifier
#sklearn makine öğrenmesi kütüphanesi
#KNeighborsClassifier KNN sınıflandırma algoritması
X = [
    [15, 300, 22, 50],  
    [80, 850, 45, 10],  
    [45, 600, 30, 20],  
    [25, 450, 25, 80],  
    [120, 950, 50, 5],   
    [35, 520, 28, 30]   
] #data setimiz

y = ["Red", "Onay", "Onay", "Red", "Onay", "Red"]

model = KNeighborsClassifier(n_neighbors=3) #model en yakın 3 noktayı kullanır

model.fit(X, y) #modeli eğitiyoruz
#kullanıcı verileri girer


gelir = int(input("Aylık Geliriniz (bin TL): "))
skor = int(input("Kredi Skorunuz (1-1000): "))
yas = int(input("Yaşınız: "))
borc = int(input("Mevcut Borç Miktarınız (bin TL): "))
#kullanıcının girdiği değerler modele gönderiliyor.
yeni_basvuru = [[gelir, skor, yas, borc]] #model tahminde bulunur
tahmin = model.predict(yeni_basvuru)

print("\nBanka Kararı:", tahmin[0])

