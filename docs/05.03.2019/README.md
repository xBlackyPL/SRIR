# Systemy równoległe i rozproszone - 05.03.2019
---

### Wydajność
Warunku wydajnego korzystania z pamięci:


###### Czas 
Proces korzysta z danych lub instrukcji z których korzystał w najbliższej przeszłości (np. pętle, stosy, lokalne zmienne)


###### Przestrzeń 
Proces odnosi się kolejno do najbliższych sąsiadów w przestrzeni adresów


###### Kolejność 
Najbardziej prawdopodobne w kolejnym kroku czasowym są następujące po sobie odniesienia 


### Analiza wydajności
Analizie muszą podlegać zarówno sprzętowe jak i programowe składowe systemu.

__Testy mogą być wykonywane w sposób:__
_statyczny:_ odbywa się na etapie tworzenia programu (przed jego uruchomieniem). Sprawdza poprawność kodu pod kątem statycznym i semantycznym.
_dynamiczny:_ odbywa się po stworzeniu programu i jego uruchomieniu

### parametric computing 
###### pierwsze podejście:
kod sekwencyjny + dużo procesów = przyspieszenie
	

###### poprawka na prawo Amdahla:
kod sekwencyjny + nie tak dużo wydajnych procesów = przyspieszenie
(to dlatego z reguły komputery mają do 4 procesorów.

### I/O dominant applications
Z dwóch komputerów równoległych o tym samym zsumowanym wskaźniku wydajności CPU lepszą wydajność dla aplikacji z dominującymi operacjami wejścia/wyjścia będzie miał ten, który posiada wolniejsze procesory.

	A w praktyce:
	Jeśli pętla obliczeniowa trwa minuty, a dane mogą zostać przesłane w ciągu sekund, to prawdopodobnie jest to dobry kandydat na program równoległy.