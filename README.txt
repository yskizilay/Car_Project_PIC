İlk önce kullandığım malzemeleri yazayım:

pickit 2 pic programlayıcı
16F887
breadboard
DRF7020D13 RF haberleşme kitleri 2 tane, birisi bilgisayara takılı diğeri pic’e
USB to TTL çevirici
4 tane DC Motor
4 tane tekerlek 
Genel Şase
2 tane L298N motor sürücüsü 
720p HD camera
FPV Alıcı - Verici ( kamera için ) 
Kamerayı Bilgisayara bağlamak için de video capture card 
Aydınlatma için önde 4 tane led
Li-Po pil + Balanslı  şarj aleti
gerekli bağlantılar için civata somun pul ve yapıştırmak için slikon + tabancası



İlk önce projeye başlamadan önce bilgisayardan veri aktarımı yapmaya çalıştım usb ile, klasik led yakma olayı. 
ondan sonra kablosuza çevirdim RF ler ile. sonra motorları sürmeye çalıştım. L298N ile. 4 x 4 olduğu için araba 2 tane sürücü kullandım.
Burada PİC’i devreden hiç çıkarmadan ICSP bağlantıları ile programladım. 
Birde PicKit 2 de PIC C COMPILER ile  debug yapınca otomatik pic’e veri gönderiyor.
Bu da çok pratik oldu programlarken. Burada arabada püf noktalardan biris pili oldu, 
eğer lipo kullanılmaz ise gerçekten istenilen performansı vermiyor. Lipo piller bu konuda çok iyi. 
Biraz pahalılar ama keyif veriyorlar. Tam dolu bir pilde 1 saat sürüş imkanı oluyor, üstelik pil 1Ah. 
yani 3ah lik felan takılsa 3 saatten fazla götürür. Diğer yazılım olayını felan kodlarda biraz anlattım.
Fotoğraflarını da ayrı yetten çekeyim göndereyim buna ek olarak. Birde kullandığım bütün programları ve eklerini de dosyanın için koydum.
Birde Bilgisayardan kodları için C# dan bilgisayar mühendisi bir arkadaşa küçük bir program yazdırdım. 
Programın yaptığı W A S D ye göre com porta serialwrite göndermek. Com da ki RF verici de arabada ki alıcıya gönderiyor.
Pic deki programa görede gelen veriyi işliyorum. Olay bu. birde kamera için ayrı bir rf kanalı lazım çünkü kamera her zaman açık olacağı için RF leri meşgul ediyor,
aynı kanalı kullanılırsak aynı anda kamera ve kontrol yapamayız. O yüzden ayrı bir RF modül ile pic den bağımsız bir şekilde veri transferi yaptım.
bilgisayara da capture card aracılığı ile görüntüyü aktarmış oldum. 
Bilgisayarda APM 2.6 uçuş kartının bir arayüzü olan MİSSİON PLANNER uygulamasını indirdim. Oradan da kamerayı açarak görmüş oldum.
Bu uygulamayı kullanmamın sebebi ilerde drone için kullanacağım sürücü kartlarının bu firmaya ait olması, 
ve bu arayüz ile kullanacak olmam. Çok rahat ve güzel bir arayüz yapmışlar tavsiye ederim. 
