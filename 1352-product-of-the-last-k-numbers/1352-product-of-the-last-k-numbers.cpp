class ProductOfNumbers {
private:
    vector<int> prefixProducts;  
  
public:
    
    ProductOfNumbers() {
        prefixProducts.push_back(1);
    }
  
    
    void add(int num) {
        if (num == 0) {
            prefixProducts.clear();
            prefixProducts.push_back(1);
            return;
        }
      
        prefixProducts.push_back(prefixProducts.back() * num);
    }
  
    
    int getProduct(int k) {
        int arraySize = prefixProducts.size();
      
        if (arraySize <= k) {
            return 0;
        }
      
        return prefixProducts.back() / prefixProducts[arraySize - k - 1];
    }
};

