double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[]){
	int idx = 0;
	double pay = 0;
	while(orderItemID[idx] != 0){
		int k = 0;
		while(itemID[k] != 0){
			if(orderItemID[idx] == itemID[k]){
				int j = 0;
				int flag = 0;
				while(onSaleItemID[j] != 0){
					if(onSaleItemID[j] == orderItemID[idx]){
						flag = 1;
						break;
					}
					j++;	
				}
				if(flag == 1)
					pay += price[k]*orderQuantity[idx]*0.8;
				else pay += price[k]*orderQuantity[idx];	
			}
			k++;
		}
		idx++;
	}
	if(pay < 490) pay +=80;
	return pay;
}
