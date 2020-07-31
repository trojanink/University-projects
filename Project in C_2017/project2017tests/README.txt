Περιεχόμενα: 

* reviews_tiny.txt : μικρό αρχείο με κριτικές, για να μπορείτε να κάνετε ελέγχους 
αποτελεσμάτων και με το χέρι.
* input_tiny.txt : ενδεικτική είσοδος, κατάλληλη για το μικρό αρχείο κριτικών
* output_tiny.txt: η έξοδος που πρέπει να βγάλει το πρόγραμμα με χρήση των δύο παραπάνω.

* reviews_small.txt : μέτριο αρχείο με κριτικές
* input_small.txt : ενδεικτική είσοδος, κατάλληλη για το μέτριο αρχείο κριτικών
* output_small.txt: η έξοδος που πρέπει να βγάλει το πρόγραμμα με χρήση των δύο παραπάνω.

* reviews_large.txt : τεράστιο αρχείο με κριτικές
* input_large.txt : ενδεικτική είσοδος, κατάλληλη για το τεράστιο αρχείο κριτικών
* output_large.txt: η έξοδος που πρέπει να βγάλει το πρόγραμμα με χρήση των δύο παραπάνω.

============================================
Τρέξτε

./project reviews_tiny.txt -p < input_tiny.txt > my_output_tiny.txt

και μετά συγκρίνετε τη δική σας έξοδο (my_output_tiny.txt) με τη δική μας (output_tiny.txt) :

diff -b my_output_tiny.txt output_tiny.txt

============================================
Τρέξτε

./project reviews_small.txt -p < input_small.txt > my_output_small.txt

και μετά συγκρίνετε τη δική σας έξοδο (my_output_small.txt) με τη δική μας (output_small.txt) :

diff -b my_output_small.txt output_small.txt

============================================
Τρέξτε

./project reviews_large.txt -p < input_large.txt > my_output_large.txt

και μετά συγκρίνετε τη δική σας έξοδο (my_output_large.txt) με τη δική μας (output_large.txt) :

diff -b my_output_large.txt output_large.txt

