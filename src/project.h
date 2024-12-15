#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <limits>
#include <sstream>
#include <fstream>

using std::string;
using std::vector;

class Produto {
  int id;
  string nome;
  float preco;

  public:
    /*Testes:
    Produto Normal
    Produto com preço negativo
    Produto com nome vazio
    Produto com id negativo
    Produto com id negativo, nome vazio e preço negativo
    */
    Produto(int id, string nome, float preco);
    int getId() const { return this->id; }
    string getName() const { return this->nome; }
    float getPrice() const { return this->preco; }
};


class Catalogo {
  vector<Produto> lista_produtos;

  public:
    /*Testes:
    Produto Normal
    Produto com o mesmo id de um produto que já está no catálogo
    */
    bool adicionarProduto(Produto prod_add);

    /*Testes:
    Instanciação da função quando a lista está vazia
    Instanciação da função quando a lista tem ao menos um produto
    */
    vector<Produto> listarProdutos();

    /*Testes:
    Procurar por id que está no catálogo
    Produrar por id que NÃO está no catálogo
    */
    std::optional<Produto> buscarProdutoPorId(int id);
};

class Pedido {
  vector<Produto> lista_produtos;
  string nome_cliente;

  public:
    Pedido(vector<Produto> produtos,string nome = "") : lista_produtos(produtos), nome_cliente(nome) {
      std::cout << "Pedido de " << this->nome_cliente << " criado com sucesso." << std::endl;
    }
    
    /*Testes:
    Produto normal
    Produto duplicado
    */
    void adicionarProduto(Produto prod_add);
    
    /*Testes:
    Total menor que 100
    Total maior que 100
    Total igual a 100
    Total não cabe em um float
    */
    float calcularTotal();
};
