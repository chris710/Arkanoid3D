Arkanoid3D
==========

Arkanoid 3D na grafikę


Dokumentacja
============

Wymagania:
  (do konsulatacji z prowadzącym)

Podział zadań:

  I. Grafika:
    1) modele i ich import
      a) paletka
         - model w Blenderze
         - tekstury
         - import
      b) piłka
         - model w Blenderze
         - tekstury
         - import
      c) klocek
         - model w Blenderze
         - tekstury
         - import
    2) otoczenie
      a) tło
         - pomieszczenie
         - tekstury
      b) efekty
         - zmiana koloru piłki
         - błyskawica na dole (?)
      c) światło
         - drugie źródło (piłka?)
      d) cząsteczki
         - rozwalanie bloków

  II. Mechanika:
    1) fizyka gry
      a) kolizje
         - piłki ze ścianami
         - paletki ze ścianami
         - piłki z blokami
         - wykrywanie kolidujących obiektów
      b) usuwanie klocków
      c) stany gry
         - menu (?)
         - pauza (?)
         - wygrana
    2) sterowanie
         - myszą
         - klawiaturą
Mechanizmy:
	Układ klas:
		Block - zwykły klocek
			RedBlock - daje ognistą piłkę, która rozwala wszystko za jednym dotknięciem
			SilverBlock - da się uszkodzić tylko od góry
			BlueBlock - daje drugą piłkę
		Session- zawiera info o stanie klocków na planszy
		BackgGround - tło i jego efekty
		Ball - piłka
		Paddle - spodek
		
Szczegóły:


Uwagi: 
Piszemy WSZYSTKO w klasach, w mainie wywołujemy po prostu gotowe f-cje z klas.
Jeżeli f-cja ma ponad 20 linii - rozbij ją na mniejsze.
Pamiętaj o nazewnictwie!
