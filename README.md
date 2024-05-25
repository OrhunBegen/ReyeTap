# ReyeTap

## 1.Musteri giris sınıfı

Program başlatılınca ilk işlemler `menu()` sınıfında yapılmaktadır.Bu sınıfta seçilen işlem sonucunda farklı sınıflar başlatılır ve program bu sınıflardan çalışır.Bunlardan ilki müşteri iişemlerini sağlayan  `CustomerMenu()` fonksiyonudur. 

`CustomerMenu()` fonksiyonu çağırıldığı zaman kullanıcıyı iki seçenek karşılar.
1.Hesap oluştur
2.Giriş yap 


1 nolu seçenek seçildiğinde `addCustomer()` fonksiyonu çağrılır.Bu fonksiyon kullanıcıdan bazı bilgilerini ister.Bu bilgiler aşağıdaki gibidir:
1.Müşteri adı 
2.Müşteri soyadı
3.Müşteri adresi 
4.Müşteri telefon numarası 
5.Müşteri e-mail
6.Şifre

Bu bilgiler `Customer` adını verdiğimiz structa atanır.

Ad ve Soyad değişkenlerini kullanıcıdan alırken `ScanfOnlyAlphabetic()` fonksiyonu ile girilen karakterlerin sadece harf olduğunu kontrol eder.

'q' tuşu ile ise çıkış yapılır.

Aynı şekilde telefon numarası alındıktan sonra `ScanfOnlyNumeric()` fonkiyonu ile girilen her bir karakterin numeric olduğu kontrol edilir.
Eğer girilen telefon numarası 11 haneli ve numeric ise `CheckPhoneExistInFile()` fonksiyonu ile girilen telefon numarasını farklı bir kullanıcının kaydedip etmediğini kontrol eder.

Kullanıcıdan mail adresi alındıktan sonra `CheckEmail()` fonkiyonu ile girilen mailin gmail.com,outlook.com veya email.com uzantılı olup olmadığı kontrol edilir ve mail formatındaysa `CheckMailExistInFile()` fonksiyonu ile girilen mailin daha önce farklı bir kullanıcı tarafından kaydedilip edilmediğini kontrol eder.

Şifre girildikten sonra ise `passwordCheck()` fonksiyonu ile şifrenin en az 6 karakter olup olmadığı kontrol edilir.


Son olarak müşteriye bir ID atanır ve kullanıcı kaydı tamamlanır. Müşteriye ID aşağıdaki gibi atanır ve hesap oluşturulan her bir müşteri `musteri.dat` dosyasına kaydedilir.

![ilk kod](https://github.com/OrhunBegen/ReyeTap/assets/146104421/d20ce9ad-f7db-4897-97a7-510d3ff3c36b)

2 nolu seçenek seçildiğinde ise `LoginCustomerReturnID()` fonksiyonu ile kullanıcı hesabına giriş yapılır.Burada kullanıcıdan e-mail adresi ve şifresi istenir.
`CheckEmail()` ve `passwordCheck()` fonksiyonları ile kontroller yapılır.

Ardından musteri.dat dosyası açılır ve girilen e-mail adresi  ve şifrenin doğruluğu kontrol edilir.Doğruysa giriş yapılır,değilse başa dönerek bilgilerin tekrar girilmesini sağlar.

![image](https://github.com/OrhunBegen/ReyeTap/assets/146104421/19b10b70-124c-4e18-a9ca-364443ec974d)


Ardından `MusteriGirisYaptiMenu()` ile giriş yapıldıktan sonra yapılacak müşteri işlemleri listelenir.Bunlar aşağıdaki gibidir:

1.Sipariş ver
2.Geçmiş siparişleri göster
3.Aktif siparişleri göster
4.Hesabımı sil
5.Çıkış 

1 nolu seçenek seçilirse `MakeOrderByID()` fonksiyonu ile sipariş verilir.Bu fonksiyon şu şekilde çalışır: 
İlk olarak `BringTheAvailableFoods()` fonksiyonu çağırılır.Bu fonksiyon FoodList.txt dosyasını açarak kullanıcıya mevcut yemekleri gösterir.
Ardından müşteriden siparişi alınır ve `OrderList.txt` dosyasına yazılır.

2 nolu seçenek seçilirse `BringPassedOrders()` fonksiyonu ile geçmiş siparişler gösterilir.

`windows.h` kütüphanesi ile sistemden güncel zaman çekilir ve sipariş teslim zamanı ve güncel zaman karşılaştırılır.Güncel zamandan önce olan siparişler kullanıcıya gösterilir.
![image](https://github.com/OrhunBegen/ReyeTap/assets/146104421/ea4a63ad-1977-4695-9f57-3237a6244850)

3 nolu seçenek seçilirse `BringActiveOrders()` fonksiyonu ile aktif siparişler gösterilir.

Burada da aynı şekilde sipariş teslim zamanı,güncel zamandan küçük veya eşit olan siparişler ekranda gösterilir.

4 nolu seçenek seçilirse `RenameTheMailasOrhun()` fonksiyonu ile kullanıcının hesabı silinir.Bu fonksiyon şu sekilde çalışır; `musteri.dat` dosyası açılır ve silinmek istenen hesaba ait mail adresi 'orhun' olarak güncellenir. Bu şekilde @gmail.com vs. formatında olmadığı için giriş yapılamayacak ve hesap devre dışı bırakılacaktır.

5 nolu seçenek seçilirse ana menüye dönüş yapılır.















