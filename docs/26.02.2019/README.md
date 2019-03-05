# Systemy równoległe i rozproszone - 26.02.2019
---

### Klastry
_Źródła:  “Cluster Computing - Architecture, Operating Systems, Parallel Processing & Programming Languages”_

__General rule of thumb__

_Kod równoległy musi być szybszy od szeregowego._

### Klasyfikacje (SCHEMATY)
###### SISD 
Single Instruction stream / Single Data stream


###### SIMD 
Single Instruction stream / Multiple Data Stream - operacje na kartach graficznych


###### MISD 
Multiple Instruction stream / Single Data stream (czysto teoretycznie)


###### MIMD 
Multiple Instruction stream / Multiple Data stream - niezależny strumień instrukcji, niezależny strumień danych (mogą być te same instrukcje i te same dane)


	Każdy procesor wykonuje indywidualną sekwencje instrukcji,
	Każdy procesor pracuje nad inną częścią zagadnienia,
	Każdy procesor może komunikować się z innymi,
	Procesory mogą czekać na inne procesory bądź na dostęp do danych.

---

Ponieważ schemat MIMD zawiera w sobie wiele klas komputerów w 1988 E. Johnson zaproponował dalszy podział:
###### GMSV 
Global Memory / Shared Variables,


###### GMMP 
Global Memory / Message Passing,


###### DMSV 
Distributed Memory / Shared Variables,


###### DMMP 
Distributed Memory / Message Passing.


---

Przedstawione modele mogą również być mieszane.
Klasyfikacje dalsze:
* Multiprocessors _(Shared Memory)_
* Multicomputers _(Private Memory)_
