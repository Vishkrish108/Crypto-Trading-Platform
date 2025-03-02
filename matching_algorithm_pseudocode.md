# Version 1 - Matching closest higher bid with matching sale price.

- #### Separating into asks and bids 
asks = orderbook.asks
bids= orderbook.bids

sales=[]
sort the asks in ascending
sort the bids in ascending

- #### Matching the bids and asks
for ask in asks:                                 // 1, 10, 14, 26, 32
    for bid in bids:                             // 5, 21, 22, 24, 33 (33 matches with 26 here)
        if bid.price >= ask.price: // Match found
            sale = new order()
            sale.price = ask.price  // Asking bidder to pay ask price, not bid price

            if bid.amount == ask.amount:    // Complete match
                sale.amount=bid.amount
                sales.append(sale)
                bid.amount = 0 // to ensure its not processed again
                break
            
            if  bid.amount > ask.amount:
                sale.amount = ask.amount
                sales.append(sale)
                bid.amount = bid.amount - ask.amount 
                break

            if bid.amount < ask.amount:
                sale.amount = ask.amount
                sales.append(sale)
                ask.amount = ask.amount - bid.amount
                bid.amount = 0 
                continue
