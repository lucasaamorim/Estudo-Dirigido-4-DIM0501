# Estudo Dirigido Sobre Testes e Depuração - Boas Práticas de Programação (DIM0501)

Aluno: Lucas Apolonio de Amorim

### Para Compilar:
Do diretório principal, usando o CMake:
```bash
cmake -DCMAKE_BUILD_TYPE=Debug -B build
cmake --build build
```

Depois de compilar, o programa pode ser testado usando o ctest na pasta build (ou o nome do diretório especificado em cmake --build)
```bash
cd build
ctest
```
ou 
```bash
ctest --test-dir build
```