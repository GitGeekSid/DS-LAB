// Product.java
class Product {
    private String productId;
    private String productName;
    private int availableQuantity;
                                             
    public Product(String productId, String productName, int availableQuantity) {
        this.productId = productId;
        this.productName = productName;
        this.availableQuantity = availableQuantity;
    }

    public String getProductId() {
        return productId;
    }

    public String getProductName() {
        return productName;
    }

    public int getAvailableQuantity() {
        return availableQuantity;
    }

    // Method to check stock and reduce only if the ordered quantity is valid
    public synchronized boolean checkAndReduceStock(int orderedQuantity) {
        if (orderedQuantity <= availableQuantity) {
            availableQuantity -= orderedQuantity;
            return true;
        } else {
            return false; // Reject if ordered quantity exceeds available stock
        }
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Product)) return false;  // Using `instanceof` instead of `getClass`
        Product product = (Product) obj;
        return productId.equals(product.productId);
    }

    @Override
    public String toString() {
        return productName + " [Available Quantity: " + availableQuantity + "]";
    }
}

// Order.java
class Order {
    private static int orderCount = 1000; // Counter for generating unique order IDs
    private Product[] products;
    private int[] quantities;
    private boolean isConfirmed = false;
    private String orderId;

    public Order(Product[] products, int[] quantities) {
        this.products = products;
        this.quantities = quantities;
    }

    public synchronized boolean confirmOrder() {
        // First check if all products have enough stock
        for (int i = 0; i < products.length; i++) {
            if (quantities[i] > products[i].getAvailableQuantity()) {
                return false;  // Cancel order if any product doesn't have enough stock
            }
        }

        // If all products have sufficient stock, reduce stock and confirm the order
        for (int i = 0; i < products.length; i++) {
            products[i].checkAndReduceStock(quantities[i]);
        }

        isConfirmed = true;
        generateOrderId();
        return true;
    }

    private void generateOrderId() {
        orderId = "ORD" + (++orderCount);  // Using a custom counter to generate Order ID
    }

    public boolean isConfirmed() {
        return isConfirmed;
    }

    public String getOrderId() {
        return orderId;
    }

    @Override
    public String toString() {
        String result = "Order Details: \n";
        for (int i = 0; i < products.length; i++) {
            result += products[i].getProductName() + " (Quantity Ordered: " + quantities[i] + ")\n";
        }
        result += "Order ID: " + (isConfirmed ? orderId : "Order Cancelled") + "\n";
        return result;  // Using simple string concatenation
    }
}

// OrderProcessor.java
class OrderProcessor implements Runnable {
    private Order order;

    public OrderProcessor(Order order) {
        this.order = order;
    }

    @Override
    public void run() {
        synchronized (order) {
            if (order.confirmOrder()) {
                System.out.println("Order Confirmed! Order ID: " + order.getOrderId());
            } else {
                System.out.println("Order Cancelled due to insufficient stock.");
            }
        }
    }
}

// Main.java
public class Maaain {
    public static void main(String[] args) {
        // CASE 1: Order gets cancelled due to insufficient stock
        System.out.println("CASE 1: Insufficient Stock - Order Gets Cancelled");

        Product p1 = new Product("P001", "Laptop", 5);  // Only 5 laptops available
        Product p2 = new Product("P002", "Smartphone", 20);
        Product p3 = new Product("P003", "Headphones", 15);

        // Ordering more than the available stock for Laptop
        Product[] productsInOrder1 = {p1, p2, p3};
        int[] quantitiesInOrder1 = {10, 15, 2};  // Ordering 10 laptops, but only 5 are available

        Order order1 = new Order(productsInOrder1, quantitiesInOrder1);

        // Process order with threads
        Thread orderThread1 = new Thread(new OrderProcessor(order1));
        orderThread1.start();

        try {
            orderThread1.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Print the order details
        System.out.println(order1);


        // CASE 2: Order gets confirmed due to sufficient stock
        System.out.println("\nCASE 2: Sufficient Stock - Order Gets Confirmed");

        Product p4 = new Product("P004", "Tablet", 10);  // 10 tablets available
        Product p5 = new Product("P005", "Camera", 25);
        Product p6 = new Product("P006", "Monitor", 12);

        // Ordering within the available stock for all products
        Product[] productsInOrder2 = {p4, p5, p6};
        int[] quantitiesInOrder2 = {3, 5, 4};  // Ordering within available quantities

        Order order2 = new Order(productsInOrder2, quantitiesInOrder2);

        // Process order with threads
        Thread orderThread2 = new Thread(new OrderProcessor(order2));
        orderThread2.start();

        try {
            orderThread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Print the order details
        System.out.println(order2);
    }
}
