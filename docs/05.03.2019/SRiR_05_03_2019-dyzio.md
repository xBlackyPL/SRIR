# Systemy równoległe i rozproszone 
~ Wykład 05-03-2019 / Wtorek 10:30 / II 

## Wydajność
 
**parametric computing** - pierwsze podejscie - mamy gigantyczną ilosc danych  
Kod sekwencyjny + duzo procesorów => przyspieszenie

**Poprawka na prawo Amndhal'a**
Kod sekwencyjny + nie tak duzo wydajnych procesorów => przyśpieszenie

**I/O dominant applications** - z dwóch komputerów równoległych o tej samym zsumowanym wskaźniku wydajności CPU lepszą wydajność dla aplikacji dominującymi operacjami i/o będzie miał ten który posiada wolniejsze procesory

A w praktycve jeśli pętla obliczeniowa trwa minuty a dane mogą zostać przesłane w cigu sekund, to prawdopodobnie jest to dobry kandydat na program równoległy

## PBS - portable batch system

System kolejkowy na komuterach obliczeniowych, 
* https://en.wikipedia.org/wiki/Portable_Batch_System 
* https://github.com/pbspro/pbspro
* https://docs.cyfronet.pl/pages/viewpage.action?pageId=14189903

Użytkownik powinien poprosić o minimalną ilość zasobów gdyż system kolejkowy przydzieli nam zasoby z większym priorytetem.
[Komendy](https://task.gda.pl/material/kursy/pbs-2013/1.html)

- `qsub` - wstawienie zadania do kolejki jako skrypt PBS
- `qstat` - spawdzenie statusu zadania wstawionego do kolejki
- `qdel` - usuwa zadania z kolejki
- `qalter` - zamiana parametrów zadania w kolejce
- `tracejob` - 

### Skrypty PBS

`#PBS -V` - odziedziczenie zmiennych srodowiskowych po użytkowniku, bardzo ważny przełącznik

- Jest jeszcze system kolejkowy **MAUI**.
- Rysunki i wykresy można wykonywać za pomocą `gnuplot`


## Cwiczenia 05-03-2019 

1. Napisz projekt w którym dwa procesy przekazują sobie wektory zbudowane z 1 000 000 elementów typu float.
2. Użyj MPI_Wtime() do zmierzenia potrzebnego obustronną komunikacje
3. Zbadaj jak uzyskane wyniki zalezą od wielkosci komunikatu.
**Badanie tematu i inicjatywa**
4. Wyniki przedstaw na rysunkach (np. gnuplot)

`mpicc <PROGRAM.C>`
`mpirun <OUT.A>`

```
[dyzio@Razor6 cw1]$ mpicc cw1.c
[dyzio@Razor6 cw1]$ mpirun -np 2 a.out    
```
