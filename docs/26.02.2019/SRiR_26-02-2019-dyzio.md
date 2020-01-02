# Systemy równoległe i rozproszone

~ Wykład 26-02-2019 / Wtorek 10:30

## Klasyfikacje
* SISD (ang. single instruction, single data) - przetwarzany jest jeden strumień danych przez jeden wykonywany program - komputery skalarne (sekwencyjne).
* SIMD (ang. single instruction, multiple data) - przetwarzanych jest wiele strumieni danych przez jeden wykonywany program - tzw. komputery wektorowe.
* MISD (ang. multiple instruction, single data) - wiele równolegle wykonywanych programów przetwarza jednocześnie jeden wspólny strumień danych. W zasadzie jedynym zastosowaniem są systemy wykorzystujące redundancję (wielokrotne wykonywanie tych samych obliczeń) do minimalizacji błędów.
* MIMD (ang. multiple instruction, multiple data) - równolegle wykonywanych jest wiele programów, z których każdy przetwarza własne strumienie danych - przykładem mogą być komputery wieloprocesorowe, a także klastry i gridy.

(https://pl.wikipedia.org/wiki/Taksonomia_Flynna)[https://pl.wikipedia.org/wiki/Taksonomia_Flynna]

## MIMD
* GMSV (kilka procesów ma wspólną pamieć) - Global memory / Shared variables
* GMMP - Global memory / Message passing
* DMSV -  Distributed memory / Shared variables
* DMMP - Distributed memory / Message passing (Na ćwiczeniach)

## Plusy i minusy rozproszenia

Plusy:
* wysoka moc obliczeniowa i przepustowosc
* niezawodnosc
* odpornosc na awarie
* wysoki stosunek jakosc/cena
* mozliwosc rozbudowy (więcej sprzętu)
* możliwość przekraczania ograniczen technologicznych
* łatwość zastosowania w wielu problemach obliczeniowych (systemy wielo-agentowe, algorytmy rojowe)

Minusy:
* ograniczona ilość oprogramowania
* wydajność sieci ma kolosalny wpływ na wydajność systemu (WAŻNE)
* problemy z bezpieczeństwem (większe biezpieczenstwo -> spadek wydajnosci)

### Jak zbudować tani superkomputer?

* połączenie wielu komputerów 

Zagadnienia:
* wzdajność
* sprzęt
* OS - system operacyjny
* middleware (warstwa między maszyną a aplikacją)
* aplikacja

## Warstwowy model klastra
(https://coreos.com/blog/cluster-osi-model.html)[https://coreos.com/blog/cluster-osi-model.html]

Główne przyczyny utraty mocy obliczeniowej (superkomputery wykorzystują 10% szczytowej mocy obliczeniowej)
* problem 
* algorytm (algorytmy przystosowane do równoległości oraz nie przystosowane)
* język programowania i kompilator (są języki do tworzenia aplikacji równoległych)
* system operacyjny
* hardware

## Wydajność 
* MIPS - milion instructions per second
* FLOPS - floating operations per second
* Czas wykonania - dla każdego problemu 

Przyśpieszenie: Sp = T1 / Tp  %% (p - ilość komputerów)
Efektywność: Ep = Sp/P = T1 / p * Tp

Inne parametry: redundancja (ile wzrosła ilosc operacji dla 1 procesora / dla wielu procesorów), wykorzystanie, jakość

### Przyśpieszenie / Ilość procesorów
Granica optymistyczna - liniowe przyśpieszenie
Granica pesymistyczna - Log(2)N 

Prawo Amdhal'a - dlaczego mamy spadek przyśpieszania wraz ze wzrostem ilości procesorów i ilością kodu równoległego (i dlaczego to nie ma sensu przy dużej ilości procesorów)


## Organizacja zajęć

* Rozwiązania możemy napisać w czym chcemy - liczy się wynik
* 3 nieobecności - wykład i ćwiczenia to jeden blok (wykład obowiązkowy)
* Zadania indywidualne - tydzień na oddanie (do wtorku 10:30)
* Projekt zaliczeniowy
* Cel pracy - stworzyć równoległe rozwiązanie wydajniejsze niż szeregowe  


## Cwiczenia - nota dostępowa

Adres wewnętrzny: 10.10.100.186
Adres zewnętrzny: XX.YY.ZZ.VV
Logoanie zdalne: `ssh {login}@zin1.geol.agh.edu.pl -p {port}`
Port: jedenosiemsześć22

Chcemy dodać do kolejki dodajemy skrypt PBS:

1. logowanie do nody dostepowej
2. kompilacja i testowe wykonanie (czy się kompiluje, kod jest poprawny)
3. modyfikacja skryptu PBS i dodanie do kolejki

**mpicc** - kompilator


>> end