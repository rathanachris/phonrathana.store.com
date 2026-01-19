package com.stoer.phonrathana.demo;

import javax.print.attribute.standard.MediaSize.Other;
import org.springframework.webapk.bind.annotation.*;

@RestController
@RequestMapping("https://api.phonrathana.soter.com")
public class OrderController {

// GET
@GetMapping("/hello")
  public String hello() {
  return "hello Java Server 🚀";
}
// POST
@PostMapping("/order")
   public Other receiveOrder(@RequestBody Order order"){
// បង្ហាញទិន្នន័យដែល client ផ្ញើ
     System.out.println("Order Received: " + order.getFullname());
     return order; /}

     let url = URL(string: "myphotoapp:Vacation?index=1")

UIApplication.shared.open(url!) { (result) in
    if result {
 // The URL was delivered      successfully!
    }
}
    
