#include "project.h"


/**
 * Construtor da classe Produto.
 * 
 * Verifica se os parâmetros de entrada são válidos e lança uma exceção caso contrário.
 * 
 * @param id O ID do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * 
 * @throws std::string Exceção lançada caso o ID seja negativo, o nome seja vazio ou o preço seja negativo.
 */
  Produto::Produto(int id, string nome, float preco) {
    std::vector<string> errors;
    if (id < 0) errors.push_back("ID não pode ser negativo.");
    if (nome == "") errors.push_back("Nome não pode ser vazio.");
    if (preco < 0) errors.push_back("Preço não pode ser negativo.");
    
    if (errors.empty()) {
      this->id = id;
      this->nome = nome;
      this->preco = preco;
    } else {
      std::ostringstream oss;
      for (auto &error : errors) oss << error << std::endl;
      throw(oss.str());
    }
  }

  /**
   * Adiciona um produto ao catálogo.
   * 
   * Verifica se um produto com o mesmo ID já existe no catálogo e lança uma aviso caso positivo.
   * Caso contrário, adiciona o produto ao catálogo e lança uma mensagem de sucesso.
   * 
   * @param prod_add O produto a ser adicionado.
   * 
   * @return true se o produto for adicionado com sucesso, false caso contrário.
   */
  bool Catalogo::adicionarProduto(Produto prod_add) {
    for (auto &prod : lista_produtos) {
      if (prod.getId() == prod_add.getId()) {
        std::cout << "Produto não adicionado, ID Repetido." << std::endl;
        return false;
      }
    }

    lista_produtos.push_back(prod_add);
    std::cout << "Produto adicionado com sucesso." << std::endl;
    return true;
  }


  /**
   * Retorna uma cópia do vetor de produtos do catálogo.
   * 
   * Caso o catálogo esteja vazio, lança um aviso.
   * Caso contrário, imprime a lista de produtos com seus respectivos IDs, nomes e preços.
   * 
   * @return Uma cópia do vetor de produtos do catálogo.
   */
  vector<Produto> Catalogo::listarProdutos() {
    if (lista_produtos.empty()) {
      std::cout << "O Catálogo está vazio." << std::endl;
    } else {
      std::cout << "Lista de Produtos: " << std::endl;
      for (auto &prod : lista_produtos) {
        std::cout << "Produto #" << prod.getId() << ":" << std::endl;
        std::cout << "Nome: " << prod.getName() << std::endl;
        std::cout << "Preço: " << prod.getPrice() << std::endl;
        std::cout << std::endl;
      }
    }
    return lista_produtos;
  }

  /**
   * Procura um produto pelo seu ID no catálogo.
   * 
   * Caso o produto seja encontrado, imprime uma mensagem de sucesso e retorna o produto.
   * Caso contrário, retorna um std::nullopt.
   * 
   * @param id O ID do produto a ser procurado.
   * 
   * @return O produto encontrado ou um std::nullopt se o produto não for encontrado.
   */
  std::optional<Produto> Catalogo::buscarProdutoPorId(int id) {
    for (auto &prod : lista_produtos) {
      if (prod.getId() == id) {
        std::cout << "Produto #" << prod.getId() << " encontrado." << std::endl;
        return prod;
      }
    }
    return std::nullopt;
  }

  
  /**
   * Adiciona um produto ao pedido.
   * 
   * @param prod_add O produto a ser adicionado.
   */
  void Pedido::adicionarProduto(Produto prod_add) {
    lista_produtos.push_back(prod_add);
  }
  
/**
 * Calcula o total do pedido considerando um possível desconto.
 *
 * Este método soma o preço de todos os produtos no pedido. Se o total for
 * igual ou superior a 100, aplica um desconto de 10%. Caso o valor total
 * exceda o limite máximo de um float, lança uma exceção.
 *
 * @return O valor total do pedido após possíveis descontos.
 *
 * @throws std::string Exceção lançada caso ocorra overflow no valor total.
 */
  float Pedido::calcularTotal() {
    float total = 0;
    for (auto &prod : lista_produtos) {
      if (total > std::numeric_limits<float>::max()-prod.getPrice()) throw("Overflow no Valor total.");
      total += prod.getPrice();
    }
    std::cout << "Total sem desconto: " << total << std::endl;
    if (total >= 100.0) {
      std::cout << "Desconto Aplicado." << std::endl;
      total *= 0.9;
      std::cout << "Total com desconto: " << total << std::endl;
    }
    return total;
  }