# klikowce

Rozwiązanie zadania [Klikowce](http://main.edu.pl/pl/archive/pa/2008/kli).  

Opiera się na zastosowaniu kompozycji, czyli znalezieniu liczby rozwiązań równania Diofantesa:  
![](http://latex.codecogs.com/svg.latex?x_1 + x_2 + ... + x_k = n)  
$$x_i \in \mathbb{N}, x_i \ge 1$$  
w których liczby są ustawione w kolejności nierosnącej. $$n$$ jest tuaj liczbą wierzchołków, zaś $$k$$ liczbą składowych spójnych. Nie konstruujemy grafu, ponieważ w zadaniu chodzi tylko o policzenie ilości kombinacji.

Liczby klikowców dla kolejnych $$n$$ tworzą prawdopodobnie [ciąg oeis](http://oeis.org/search?q=1%2C2%2C3%2C5%2C7%2C11%2C15%2C22&language=english&go=Search) - [A000041](http://oeis.org/A000041)

### Wyniki
![1/10](https://github.com/banan314/klikowce/blob/master/res.PNG)
