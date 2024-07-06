ID:208336701
MAIL:ofekmarom9@gmail.com
# עצים - STL, Templates, and Iterators - מטלה 4
במטלה הזאת מימשתי קונטיינר המייצג עץ k-ארי גנרי שמכיל מפתחות מכל סוג (למשל מספרים, מחרוזות ומחלקות). 
במטלה מימשתי את האופרטורים הבאים:
1. איטרטור Pre-Order - האיטרטור הזה עובד עבור עץ בינארי בלבד! עבור עץ כללי נבצע DFS.
2. איטרטור Post-Order - האיטרטור הזה עובד עבור עץ בינארי בלבד! עבור עץ כללי נבצע DFS.
3. איטרטור In-Order  - האיטרטור הזה עובד עבור עץ בינארי בלבד! עבור עץ כללי נבצע DFS.
5. איטרטור BFS - סריקת העץ לרוחב (משמאלי לימין) (עובד על עץ כללי).
6. איטרטור DFS - סריקת העץ בעזרת אלגוריתם DFS (עובד על עץ כללי).
7. איטרטור Heap - הפיכת עץ בינארי לערימת מינימום ואז מעבר עליו בשיטת BFS

שם הקונטיינר שמימשתי הוא `tree`. ויש בו את המתודות הבאות:
1. המתודה `add_root` - הוספת השורש של העץ. המתודה מקבלת ערך כלשהו ושמה אותו בשורש העץ.
2. המתודה `add_sub_node` - הוספת ילד לאב. המתודה מקבלת את ערך האב ואת הערך של הבן שעכשיו ניצור ויוצרת בן עבור אותו אב.
3. המתודות `begin_pre_order`, `end_pre_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Pre-Order.
4. המתודות `begin_post_order`, `end_post_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Post-Order.
5. המתודות `begin_in_order`, `end_in_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת In-Order.
6. המתודות `begin_bfs_scan`, `end_bfs_scan`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם BFS.
7. המתודות `begin_dfs_scan`, `end_dfs_scan`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם DFS.
8. המתודה `myHeap`. המתודה הופכת עץ בינארי לערימת מינימום.
9. המתודות 'begin_heap', end_heap' . המתודות מחזירות איטרטורים עבור הערימה
10. המתודה delete_tree שהיא בעצם תהיה Destructor המוחק את כל העץ.
11. פונקציית הדפסה. אם שם העץ הוא tree1 אז שנרצה להדפיס אותו בעזרת GUI נכתוב :
cout << tree1;
ובהרצת התוכנית ייפתח GUI שבתוכו מופיע העץ הזה.
השתמשתי בספרייה sfml בשביל הGUI. 

קיים קובץ main שבו אני מדגים את אופן פעולת התוכנית ואת ההדפסות השונות של כל איטרטור על מספר סוגי עצים שונים.
בנוסף, כתבתי את המחלקה Complex (המייצגת מספרים מדומים) והשתמשתי גם בה בקובץ ה MAIN והדגמתי את אופן פעולת האיטרטורים גם עליה.

בנוסף, כתבתי את הקובץ test.cpp המכיל בדיקות מקיפות לקוד שלי ומוודא שהאיטרטורים אכן עובדים כמו שהם צריכים לעבוד ושהעץ נבנה בצורה נכונה.

המחלקות שכתבתי על מנת לממש את זה הם: 
1. Complex.cpp/hpp - complex numbers
2. Node.hpp - represent node in the tree
3. tree.hpp/tpp - represent aa header file of the tree and a tpp file for all the implementation and the templates of the tree class
4. TreeIteratorBFS.tpp,TreeIteratorDFS.tpp,TreeIteratorHeap.tpp,
TreeIteratorInOrder.tpp,TreeIteratorPostOrder.tpp,
TreeIteratorPreOrder.tpp   - the implementation of all the iterators for the tree class

השתמשתי בקוד בספריות הבאות:
sfml, iostream, cmath, vector, queue, stack, functional, stdexcept, sstream.


##הרצת התוכנית 
כדי להריץ את התוכנית כותבים בטרמינל make tree המריץ את קובץ הMAIN המדגים את את העצים השונים ואת הרצת האופרטורים עליהם.
כדי להריץ את קובץ הטסטים כותבים בטרמינל make runtest.

   
