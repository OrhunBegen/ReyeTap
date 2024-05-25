# ReyeTap

## 1.Musteri giris sınıfı

Program başlatılınca ilk işlemler 'menu()' sınıfında yapılmaktadır.Bu sınıfta seçilen işlem sonucunda farklı sınıflar başlatılır ve program bu sınıflardan çalışır.Bunlardan ilki müşteri iişemlerini sağlayan   'CustomerMenu()' fonksiyonudur. 

'CustomerMenu()' fonksiyonu çağırıldığı zaman kullanıcıyı iki seçenek karşılar.
1.Hesap oluştur
2.Giriş yap 


1 nolu seçenek seçildiğinde 'addCustomer()' fonksiyonu çağrılır.Bu fonksiyon kullanıcıdan bazı bilgilerini ister.Bu bilgiler aşağıdaki gibidir:
1.Müşteri adı 
2.Müşteri soyadı
3.Müşteri adresi 
4.Müşteri telefon numarası 
5.Müşteri e-mail
6.Şifre

Bu bilgiler 'Customer' adını verdiğimiz structa atanır.

Ad ve Soyad değişkenlerini kullanıcıdan alırken 'ScanfOnlyAlphabetic()' fonksiyonu ile girilen karakterlerin sadece harf olduğunu kontrol eder.

'q' tuşu ile ise çıkış yapılır.

Aynı şekilde telefon numarası alındıktan sonra 'ScanfOnlyNumeric()' fonkiyonu ile girilen her bir karakterin numeric olduğu kontrol edilir.
Eğer girilen telefon numarası 11 haneli ve numeric ise 'CheckPhoneExistInFile()' fonksiyonu ile girilen telefon numarasını farklı bir kullanıcının kaydedip etmediğini kontrol eder.

Kullanıcıdan mail adresi alındıktan sonra 'CheckEmail()' fonkiyonu ile girilen mailin gmail.com,outlook.com veya email.com uzantılı olup olmadığı kontrol edilir ve mail formatındaysa 'CheckMailExistInFile()' fonksiyonu ile girilen mailin daha önce farklı bir kullanıcı tarafından kaydedilip edilmediğini kontrol eder.

Şifre girildikten sonra ise 'passwordCheck()' fonksiyonu ile şifrenin en az 6 karakter olup olmadığı kontrol edilir.


Son olarak müşteriye bir ID atanır ve kullanıcı kaydı tamamlanır. Müşteriye ID aşağıdaki gibi atanır;

\`\`\`
c1.id = ftell(ptr)/sizeof(Customer) + 1;
\`\`\`

Hesap oluşturulan her bir müşteri 'musteri.dat' dosyasına kaydedilir.
\`\`\`
FILE *ptr= fopen("musteri.dat","a+b");
fseek(ptr, 0, SEEK_END);
fwrite(&c1, sizeof(Customer), 1, ptr);
fclose(ptr);
printf("\n\nMusteri eklendi \n");
\`\`\`


2 nolu seçenek seçildiğinde ise 'LoginCustomerReturnID()' fonksiyonu ile kullanıcı hesabına giriş yapılır.Burada kullanıcıdan e-mail adresi ve şifresi istenir.
'CheckEmail()' ve 'passwordCheck()' fonksiyonları ile kontroller yapılır.

Ardından musteri.dat dosyası açılır ve girilen e-mail adresi  ve şifrenin doğruluğu kontrol edilir.Doğruysa giriş yapılır,değilse başa dönerek bilgilerin tekrar girilmesini sağlar.
\`\`\`
FILE *ptr = fopen("musteri.dat", "r+b");
    while (fread(&c1, sizeof(Customer), 1, ptr) == 1)
    {
        if (strcmp(c1.email, Email) == 0 && strcmp(c1.password, Password) == 0)
        {
            printf("Giris basarili\n");
            fclose(ptr);
            return c1.id;
        }
    }
    fclose(ptr);
    printf("Giris basarisiz\n");
    return 0;
\`\`\`




