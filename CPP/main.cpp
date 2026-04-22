#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <variant>
#include <cctype>
#include <thread>
#include <queue>
#include <future>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <unordered_set>
using namespace std;

// update from an exchange for a symbol 
// client 
    // symbols 
    // rate limit its updates 
    // best price received 
    // update ids received 
    // updates received at timestmaps 

// get_updates for clients 
// client update 
    // no update twice 
    // no stale updates update.timestamp < currentTime - STALE_THRESHOLD
    // best price the newer updates != 




/*

Item

WareHouse 
    - id
    - capacity
    - currentStock map<itemId, quantity>

InventoryManager

    - items: itemId -> item
    - warehouses: warehouseid -> warehouse 
    - itemWarehouses: itemIdToWarehouseID - priorityQueue (quantity for itemId, warehouseid, *warehouses)
    - EXPIRY
    - centralHubCapacity, currentCentralHubCapacity 

    * addWarehouse
    * addStock (warehouseid, itemid, quantity)
        - delete this warehouseid from itemWareHouses[warehouseid]
        - update this warehouse 
        - reinsert it in itemWareHouses[warehouseid]

    * requestTransfer(itemId, quantity, timestamp)
        what warehouse to chose?
            - highest available stock 
            - lowest warehosue id 

        iterate over the ware houses for this item frmo itemWarehouses map 
        update the warehouse stock for this item 
        put this warehouse id in reprioritize warehouseids set 

        in the end put back reprioritize warehouse ids in the correponsing itemWarehouse[itemid] priorityqueue







*/











int main() {





}
