### **A. Case Explanation**
my goal was basically to simulate some sort of an IT Help Desk. In the real world, (to my understanding) IT departments dont just handle the tickets in order, they handle them based off severity; some sort of hierarchy, where they have to balance the "fairness" (normal ticckets) with the "emergency" (urgent tickets).

This system would need to:
1. store multiple pieces of data per ticket (id and priority in this case)
2. Allow "VIPs" to cut the line (urgent stuff)
3. keep a history of solved work that should be able to be undone if a mistake is made.

### **B. Implementation Details**
to solve this, I changed out the data structures; the int ones to a `Ticket` struct
