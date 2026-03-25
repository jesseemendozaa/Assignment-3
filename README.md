
/**
 * Description: This program implements a UNIX shell (shell1.c). User can call ./countnames which will spawn a child per input file. Each child will redirect output to a err and out file with its corresponding PID. err file displays any warnings such as missing line. out will contain how many times a name occured in the text file. In Assignment 3, the children send name counts back to the parent through a pipe and the parent prints the final combined counts of names.
 * GitHub : https://github.com/jesseemendozaa/Assignment-3
 * 
 * Author names: 
 * Jada-Lien Nguyen -
 * Jesse Mendoza -
 * Author emails: 
 * jada-lien.nguyen@sjsu.edu 
 * jesse.mendoza@sjsu.edu 
 * Last modified date: 3/23/2026
 * Creation date: 3/23/2026
 **/

## Link to Output of PDF:

[output.pdf](output.pdf)

## How to Compile Code:

Navigate to the folder where countnames.c and shell1.c is located, then enter following commands in terminal:

gcc -Wall -Wextra -g -o countnames countnames.c
gcc -Wall -Wextra -g -o shell1 shell1.c

## Run shell

./shell1

### (Can exit shell with 'quit' or 'exit')

## shell1 one file test

./countnames test/names.txt
./countnames test/names1.txt
./countnames test/names2.txt
./countnames test/namesB.txt
./countnames test/names_long.txt
./countnames test/names_long_redundant.txt
./countnames test/names_long_redundant1.txt
./countnames test/names_long_redundant2.txt
./countnames test/names_long_redundant3.txt
./countnames test/testCase1.txt
./countnames test/testCase2.txt
./countnames test/testCase3.txt

## shell1 multiple file test (expected output below...)

./countnames test/names.txt test/names1.txt
./countnames test/names.txt test/names2.txt
./countnames test/names1.txt test/names2.txt
./countnames test/names.txt test/names1.txt test/names2.txt
./countnames test/names.txt test/namesB.txt
./countnames test/testCase1.txt test/names1.txt
./countnames test/testCase1.txt test/names2.txt
./countnames test/testCase2.txt test/namesB.txt
./countnames test/testCase3.txt test/names.txt
./countnames test/testCase1.txt test/testCase3.txt
./countnames test/names_long_redundant1.txt test/names_long_redundant2.txt
./countnames test/names_long_redundant2.txt test/names_long_redundant3.txt
./countnames test/names_long_redundant1.txt test/names_long_redundant3.txt
./countnames test/names_long_redundant1.txt test/names_long_redundant2.txt test/names_long_redundant3.txt
./countnames test/names.txt test/testCase1.txt test/testCase2.txt
./countnames test/namesB.txt test/testCase1.txt test/names2.txt

## Output expected for each test case:

## ./countnames test/names.txt test/names1.txt

Tom Wu: 3
Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1

## ./countnames test/names.txt test/names2.txt

Jenn Xu: 2
Tom Wu: 1
Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1

## ./countnames test/names1.txt test/names2.txt

Jenn Xu: 2
Tom Wu: 4

## ./countnames test/names.txt test/names1.txt test/names2.txt

Jenn Xu: 2
Tom Wu: 4
Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1

## ./countnames test/names.txt test/namesB.txt

Nicky: 2
Dave Joe: 4
Yuan Cheng Chang: 6
John Smith: 2

## ./countnames test/testCase1.txt test/names1.txt

Tom Wu: 3
Mike Lam: 1
Jimmy Le: 1
J i m m y L e: 1
M ike Lam: 1
JeSsE: 1
JESSE: 1

## ./countnames test/testCase1.txt test/names2.txt

Mike Lam: 1
Jimmy Le: 1
J i m m y L e: 1
M ike Lam: 1
JeSsE: 1
JESSE: 1
Jenn Xu: 2
Tom Wu: 1

## ./countnames test/testCase2.txt test/namesB.txt

Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1
Jose Mendez: 1
Ana Nguyen: 2
Charlie Kirk: 1
Barrack Obama: 1
Tommy Obama: 1
 : 1
 Tim Tran: 1
Andrew White: 2
ANDREW WHITE: 1
Nguyen Ana: 1

## ./countnames test/testCase3.txt test/names.txt

ABRAHAM LINCOLN: 1
ABRAHAM RAMIREZ: 1
 ABRAHAM LINCOLN: 1
ADRIAN ADRIAN: 1
ADRIAN: 1
JADA NGUYEn: 1
GEORGE WASHINGTON: 2
JADA NGUYEN: 1
JORGE PEREZ: 1
JESSE MENDOZA: 1
MENDOZA JESSE: 1
Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1

## ./countnames test/testCase1.txt test/testCase3.txt

ABRAHAM LINCOLN: 1
ABRAHAM RAMIREZ: 1
 ABRAHAM LINCOLN: 1
ADRIAN ADRIAN: 1
ADRIAN: 1
JADA NGUYEn: 1
GEORGE WASHINGTON: 2
JADA NGUYEN: 1
JORGE PEREZ: 1
JESSE MENDOZA: 1
MENDOZA JESSE: 1
Mike Lam: 1
Jimmy Le: 1
J i m m y L e: 1
M ike Lam: 1
JeSsE: 1
JESSE: 1

## ./countnames test/names_long_redundant1.txt test/names_long_redundant2.txt

STEPHANIE MITCHELL: 1
CAROLYN PEREZ: 1
CHRISTINE ROBERTS: 1
MARIE TURNER: 1
JANET PHILLIPS: 1
CATHERINE CAMPBELL: 1
FRANCES PARKER: 1
ANN EVANS: 1
JOYCE EDWARDS: 1
DIANE COLLINS: 1
ALICE STEWART: 1
JULIE SANCHEZ: 1
HEATHER MORRIS: 1
TERESA ROGERS: 1
DORIS REED: 1
GLORIA COOK: 1
EVELYN MORGAN: 1
JEAN BELL: 1
CHERYL MURPHY: 1
MILDRED BAILEY: 1
KATHERINE RIVERA: 1
JOAN COOPER: 1
ASHLEY RICHARDSON: 1
JUDITH COX: 1
ROSE HOWARD: 1
JANICE WARD: 1
KELLY TORRES: 1
NICOLE PETERSON: 1
JUDY GRAY: 1
CHRISTINA RAMIREZ: 1
KATHY JAMES: 1
THERESA WATSON: 1
BEVERLY BROOKS: 1
DENISE KELLY: 1
TAMMY SANDERS: 1
IRENE PRICE: 1
JANE BENNETT: 1
LORI WOOD: 1
RACHEL BARNES: 1
MARILYN ROSS: 1
ANDREA HENDERSON: 1
KATHRYN COLEMAN: 1
LOUISE B JENKINS: 1
SARA A PERRY: 1
MARY SMITH: 1
PATRICIA JOHNSON: 1
LINDA WILLIAMS: 1
BARBARA JONES: 1
ELIZABETH BROWN: 1
JENNIFER DAVIS: 1
MARIA MILLER: 1
SUSAN WILSON: 1
MARGARET MOORE: 1
DOROTHY TAYLOR: 1
LISA ANDERSON: 1
NANCY THOMAS: 1
KAREN JACKSON: 1
BETTY WHITE: 1
HELEN HARRIS: 1
SANDRA MARTIN: 1
DONNA THOMPSON: 1
CAROL GARCIA: 1
RUTH MARTINEZ: 1
SHARON ROBINSON: 1
MICHELLE CLARK: 1
LAURA RODRIGUEZ: 1
SARAH LEWIS: 1
KIMBERLY LEE: 1
DEBORAH WALKER: 1
JESSICA HALL: 1
SHIRLEY ALLEN: 1
CYNTHIA YOUNG: 1
ANGELA HERNANDEZ: 1
MELISSA KING: 1
BRENDA WRIGHT: 1
AMY LOPEZ: 1
ANNA HILL: 1
REBECCA SCOTT: 1
VIRGINIA GREEN: 1
KATHLEEN ADAMS: 1
PAMELA BAKER: 1
MARTHA GONZALEZ: 1
DEBRA NELSON: 1
AMANDA CARTER: 1

## ./countnames test/names_long_redundant2.txt test/names_long_redundant3.txt

ANNE J POWELL: 1
JACQUELINE K LONG: 1
WANDA M PATTERSON: 1
BONNIE HUGHES: 1
STEPHANIE MITCHELL: 1
CAROLYN PEREZ: 1
CHRISTINE ROBERTS: 1
JULIA FLORES: 1
RUBY WASHINGTON: 1
LOIS BUTLER: 1
TINA SIMMONS: 1
MARIE TURNER: 1
PHYLLIS FOSTER: 1
NORMA GONZALES: 1
PAULA BRYANT: 1
DIANA ALEXANDER: 1
JANET PHILLIPS: 1
ANNIE RUSSELL: 1
LILLIAN GRIFFIN: 1
EMILY DIAZ: 1
CATHERINE CAMPBELL: 1
FRANCES PARKER: 1
ANN EVANS: 1
JOYCE EDWARDS: 1
ROBIN HAYES: 1
DIANE COLLINS: 1
ALICE STEWART: 1
JULIE SANCHEZ: 1
MARY SMITH: 2
PATRICIA JOHNSON: 2
LINDA WILLIAMS: 2
BARBARA JONES: 2
ELIZABETH BROWN: 2
HEATHER MORRIS: 1
JENNIFER DAVIS: 1
MARIA MILLER: 1
TERESA ROGERS: 1
SUSAN WILSON: 1
MARGARET MOORE: 1
DOROTHY TAYLOR: 1
LISA ANDERSON: 1
NANCY THOMAS: 1
KAREN JACKSON: 1
BETTY WHITE: 1
DORIS REED: 1
HELEN HARRIS: 1
GLORIA COOK: 1
EVELYN MORGAN: 1
JEAN BELL: 1
CHERYL MURPHY: 1
SANDRA MARTIN: 1
MILDRED BAILEY: 1
DONNA THOMPSON: 1
CAROL GARCIA: 1
RUTH MARTINEZ: 1
SHARON ROBINSON: 1
MICHELLE CLARK: 1
LAURA RODRIGUEZ: 1
SARAH LEWIS: 1
KIMBERLY LEE: 1
DEBORAH WALKER: 1
KATHERINE RIVERA: 1
JOAN COOPER: 1
ASHLEY RICHARDSON: 1
JUDITH COX: 1
ROSE HOWARD: 1
JANICE WARD: 1
KELLY TORRES: 1
NICOLE PETERSON: 1
JUDY GRAY: 1
CHRISTINA RAMIREZ: 1
KATHY JAMES: 1
THERESA WATSON: 1
BEVERLY BROOKS: 1
DENISE KELLY: 1
TAMMY SANDERS: 1
IRENE PRICE: 1
JANE BENNETT: 1
LORI WOOD: 1
RACHEL BARNES: 1
MARILYN ROSS: 1
ANDREA HENDERSON: 1
KATHRYN COLEMAN: 1
LOUISE B JENKINS: 1
SARA A PERRY: 1

## ./countnames test/names_long_redundant1.txt test/names_long_redundant3.txt

ANNE J POWELL: 1
JACQUELINE K LONG: 1
WANDA M PATTERSON: 1
BONNIE HUGHES: 1
JULIA FLORES: 1
RUBY WASHINGTON: 1
LOIS BUTLER: 1
TINA SIMMONS: 1
PHYLLIS FOSTER: 1
NORMA GONZALES: 1
PAULA BRYANT: 1
DIANA ALEXANDER: 1
ANNIE RUSSELL: 1
LILLIAN GRIFFIN: 1
EMILY DIAZ: 1
ROBIN HAYES: 1
MARY SMITH: 3
PATRICIA JOHNSON: 3
LINDA WILLIAMS: 3
BARBARA JONES: 3
ELIZABETH BROWN: 3
JENNIFER DAVIS: 2
MARIA MILLER: 2
SUSAN WILSON: 2
MARGARET MOORE: 2
DOROTHY TAYLOR: 2
LISA ANDERSON: 2
NANCY THOMAS: 2
KAREN JACKSON: 2
BETTY WHITE: 2
HELEN HARRIS: 2
SANDRA MARTIN: 2
DONNA THOMPSON: 2
CAROL GARCIA: 2
RUTH MARTINEZ: 2
SHARON ROBINSON: 2
MICHELLE CLARK: 2
LAURA RODRIGUEZ: 2
SARAH LEWIS: 2
KIMBERLY LEE: 2
DEBORAH WALKER: 2
JESSICA HALL: 1
SHIRLEY ALLEN: 1
CYNTHIA YOUNG: 1
ANGELA HERNANDEZ: 1
MELISSA KING: 1
BRENDA WRIGHT: 1
AMY LOPEZ: 1
ANNA HILL: 1
REBECCA SCOTT: 1
VIRGINIA GREEN: 1
KATHLEEN ADAMS: 1
PAMELA BAKER: 1
MARTHA GONZALEZ: 1
DEBRA NELSON: 1
AMANDA CARTER: 1

## ./countnames test/names_long_redundant1.txt test/names_long_redundant2.txt test/names_long_redundant3.txt

STEPHANIE MITCHELL: 1
ANNE J POWELL: 1
CAROLYN PEREZ: 1
JACQUELINE K LONG: 1
CHRISTINE ROBERTS: 1
WANDA M PATTERSON: 1
MARIE TURNER: 1
BONNIE HUGHES: 1
JANET PHILLIPS: 1
JULIA FLORES: 1
CATHERINE CAMPBELL: 1
RUBY WASHINGTON: 1
FRANCES PARKER: 1
LOIS BUTLER: 1
ANN EVANS: 1
JOYCE EDWARDS: 1
DIANE COLLINS: 1
ALICE STEWART: 1
JULIE SANCHEZ: 1
TINA SIMMONS: 1
HEATHER MORRIS: 1
PHYLLIS FOSTER: 1
TERESA ROGERS: 1
DORIS REED: 1
GLORIA COOK: 1
EVELYN MORGAN: 1
JEAN BELL: 1
NORMA GONZALES: 1
CHERYL MURPHY: 1
PAULA BRYANT: 1
MILDRED BAILEY: 1
DIANA ALEXANDER: 1
KATHERINE RIVERA: 1
JOAN COOPER: 1
ASHLEY RICHARDSON: 1
JUDITH COX: 1
ROSE HOWARD: 1
JANICE WARD: 1
ANNIE RUSSELL: 1
KELLY TORRES: 1
NICOLE PETERSON: 1
JUDY GRAY: 1
CHRISTINA RAMIREZ: 1
LILLIAN GRIFFIN: 1
KATHY JAMES: 1
THERESA WATSON: 1
EMILY DIAZ: 1
BEVERLY BROOKS: 1
ROBIN HAYES: 1
DENISE KELLY: 1
MARY SMITH: 3
TAMMY SANDERS: 1
PATRICIA JOHNSON: 3
IRENE PRICE: 1
LINDA WILLIAMS: 3
JANE BENNETT: 1
BARBARA JONES: 3
LORI WOOD: 1
ELIZABETH BROWN: 3
RACHEL BARNES: 1
JENNIFER DAVIS: 2
MARILYN ROSS: 1
MARIA MILLER: 2
SUSAN WILSON: 2
MARGARET MOORE: 2
DOROTHY TAYLOR: 2
LISA ANDERSON: 2
NANCY THOMAS: 2
KAREN JACKSON: 2
BETTY WHITE: 2
ANDREA HENDERSON: 1
HELEN HARRIS: 2
KATHRYN COLEMAN: 1
SANDRA MARTIN: 2
LOUISE B JENKINS: 1
DONNA THOMPSON: 2
SARA A PERRY: 1
CAROL GARCIA: 2
RUTH MARTINEZ: 2
SHARON ROBINSON: 2
MICHELLE CLARK: 2
LAURA RODRIGUEZ: 2
SARAH LEWIS: 2
KIMBERLY LEE: 2
DEBORAH WALKER: 2
JESSICA HALL: 1
SHIRLEY ALLEN: 1
CYNTHIA YOUNG: 1
ANGELA HERNANDEZ: 1
MELISSA KING: 1
BRENDA WRIGHT: 1
AMY LOPEZ: 1
ANNA HILL: 1
REBECCA SCOTT: 1
VIRGINIA GREEN: 1
KATHLEEN ADAMS: 1
PAMELA BAKER: 1
MARTHA GONZALEZ: 1
DEBRA NELSON: 1
AMANDA CARTER: 1

## ./countnames test/names.txt test/testCase1.txt test/testCase2.txt

Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1
Mike Lam: 1
Jimmy Le: 1
J i m m y L e: 1
M ike Lam: 1
JeSsE: 1
JESSE: 1
Jose Mendez: 1
Ana Nguyen: 2
Charlie Kirk: 1
Barrack Obama: 1
Tommy Obama: 1
 : 1
 Tim Tran: 1
Andrew White: 2
ANDREW WHITE: 1
Nguyen Ana: 1

## ./countnames test/namesB.txt test/testCase1.txt test/names2.txt

Jenn Xu: 2
Tom Wu: 1
Mike Lam: 1
Jimmy Le: 1
J i m m y L e: 1
M ike Lam: 1
JeSsE: 1
JESSE: 1
Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1

## ./countnames test/names.txt

### $PID.err

Warning - file test/names.txt line 2 is empty.
Warning - file test/names.txt line 5 is empty.

### $PID.out

Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1

## ./countnames test/names1.txt

### $PID.err

Warning - file test/names1.txt line 3 is empty.

### $PID.out

Tom Wu: 3

## ./countnames test/names2.txt

### $PID.err

### $PID.out

Jenn Xu: 2
Tom Wu: 1

## ./countnames test/namesB.txt

### $PID.err

Warning - file test/namesB.txt line 2 is empty.
Warning - file test/namesB.txt line 5 is empty.

### $PID.out

Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1

## ./countnames test/names_long.txt

### $PID.err

### $PID.out

MARY SMITH: 1
 : 99
PATRICIA JOHNSON: 1
LINDA WILLIAMS: 1
BARBARA JONES: 1
ELIZABETH BROWN: 1
JENNIFER DAVIS: 1
MARIA MILLER: 1
SUSAN WILSON: 1
MARGARET MOORE: 1
DOROTHY TAYLOR: 1
LISA ANDERSON: 1
NANCY THOMAS: 1
KAREN JACKSON: 1
BETTY WHITE: 1
HELEN HARRIS: 1
SANDRA MARTIN: 1
DONNA THOMPSON: 1
CAROL GARCIA: 1
RUTH MARTINEZ: 1
SHARON ROBINSON: 1
MICHELLE CLARK: 1
LAURA RODRIGUEZ: 1
SARAH LEWIS: 1
KIMBERLY LEE: 1
DEBORAH WALKER: 1
JESSICA HALL: 1
SHIRLEY ALLEN: 1
CYNTHIA YOUNG: 1
ANGELA HERNANDEZ: 1
MELISSA KING: 1
BRENDA WRIGHT: 1
AMY LOPEZ: 1
ANNA HILL: 1
REBECCA SCOTT: 1
VIRGINIA GREEN: 1
KATHLEEN ADAMS: 1
PAMELA BAKER: 1
MARTHA GONZALEZ: 1
DEBRA NELSON: 1
AMANDA CARTER: 1
STEPHANIE MITCHELL: 1
CAROLYN PEREZ: 1
CHRISTINE ROBERTS: 1
MARIE TURNER: 1
JANET PHILLIPS: 1
CATHERINE CAMPBELL: 1
FRANCES PARKER: 1
ANN EVANS: 1
JOYCE EDWARDS: 1
DIANE COLLINS: 1
ALICE STEWART: 1
JULIE SANCHEZ: 1
HEATHER MORRIS: 1
TERESA ROGERS: 1
DORIS REED: 1
GLORIA COOK: 1
EVELYN MORGAN: 1
JEAN BELL: 1
CHERYL MURPHY: 1
MILDRED BAILEY: 1
KATHERINE RIVERA: 1
JOAN COOPER: 1
ASHLEY RICHARDSON: 1
JUDITH COX: 1
ROSE HOWARD: 1
JANICE WARD: 1
KELLY TORRES: 1
NICOLE PETERSON: 1
JUDY GRAY: 1
CHRISTINA RAMIREZ: 1
KATHY JAMES: 1
THERESA WATSON: 1
BEVERLY BROOKS: 1
DENISE KELLY: 1
TAMMY SANDERS: 1
IRENE PRICE: 1
JANE BENNETT: 1
LORI WOOD: 1
RACHEL BARNES: 1
MARILYN ROSS: 1
ANDREA HENDERSON: 1
KATHRYN COLEMAN: 1
LOUISE B JENKINS: 1
SARA A PERRY: 1
ANNE J POWELL: 1
JACQUELINE K LONG: 1
WANDA M PATTERSON: 1
BONNIE HUGHES: 1
JULIA FLORES: 1
RUBY WASHINGTON: 1
LOIS BUTLER: 1
TINA SIMMONS: 1
PHYLLIS FOSTER: 1
NORMA GONZALES: 1
PAULA BRYANT: 1
DIANA ALEXANDER: 1
ANNIE RUSSELL: 1
LILLIAN GRIFFIN: 1
EMILY DIAZ: 1

## ./countnames test/names_long_redundant.txt

### $PID.err

### $PID.out

John Smith: 1
Emily Davis: 1
Michael Johnson: 1
Sophia Lee: 1
Daniel Rodriguez: 1
Mia Hernandez: 1
David Kim: 1
Olivia Brown: 1
Anthony Martinez: 1
Evelyn Jackson: 1
Christopher Gonzalez: 1
Avery Taylor: 2
Andrew Lee: 2
Aria Perez: 1
Matthew Davis: 1
Victoria Wilson: 1
William Anderson: 1
Madison Green: 1
Joshua Wright: 1
Isabella Clark: 1
Nathan Davis: 2
Natalie Adams: 1
Ethan Martin: 1
Chloe Baker: 1
Ryan Lee: 1
Samantha Perez: 1
Benjamin Wright: 1
Aaliyah Garcia: 1
Jacob Cooper: 1
Elizabeth Martinez: 1
Tyler Thompson: 1
Hannah Scott: 1
Alexander Rodriguez: 1
Makayla Turner: 1
Nicholas Nguyen: 1
Sofia Hernandez: 1
Brandon Smith: 1
Grace Lee: 1
Christian Martinez: 1
Ava Jones: 1
William Turner: 1
Ella Wilson: 1
Jonathan Lee: 2
Lily Johnson: 1
Samuel Davis: 1
Avery Adams: 2
Gabriella Clark: 1
Dylan Anderson: 1
Lauren Kim: 1
James Lewis: 1
Makenna Wright: 1
Luke Davis: 1
Aaliyah Brown: 1
Christopher Anderson: 1
Abigail Perez: 1
Daniel Lee: 1
Jayden Robinson: 1
Leah Lee: 1
Nicholas Jackson: 1
Avery Lee: 1
Emma Hernandez: 1
Ethan Brown: 1
Madison Martinez: 1
Lucas Davis: 1
Aria Wright: 1
Ryan Rodriguez: 1
Sophia Turner: 1
Benjamin Davis: 1
Ella Garcia: 1
Chloe Kim: 1
William Scott: 1
Ava Smith: 1
David Wright: 1
Natalie Martin: 1
Isabella Adams: 1
Brandon Davis: 1
Makayla Hernandez: 1
Alexander Clark: 1
Emily Rodriguez: 1
Christopher Lee: 1
Olivia Lee: 1
Samantha Martinez: 1
Daniel Anderson: 1
Mia Lee: 1
Jacob Wright: 1
Elizabeth Adams: 1
Tyler Martinez: 1
Hannah Garcia: 1
Nicholas Davis: 1
Sofia Thompson: 1
Brandon Brown: 1

## ./countnames test/names_long_redundant1.txt

### $PID.err

Warning - file test/names_long_redundant1.txt line 2 is empty.
Warning - file test/names_long_redundant1.txt line 4 is empty.
Warning - file test/names_long_redundant1.txt line 6 is empty.
Warning - file test/names_long_redundant1.txt line 8 is empty.

### $PID.out

MARY SMITH: 1
PATRICIA JOHNSON: 1
LINDA WILLIAMS: 1
BARBARA JONES: 1
ELIZABETH BROWN: 1
JENNIFER DAVIS: 1
MARIA MILLER: 1
SUSAN WILSON: 1
MARGARET MOORE: 1
DOROTHY TAYLOR: 1
LISA ANDERSON: 1
NANCY THOMAS: 1
KAREN JACKSON: 1
BETTY WHITE: 1
HELEN HARRIS: 1
SANDRA MARTIN: 1
DONNA THOMPSON: 1
CAROL GARCIA: 1
RUTH MARTINEZ: 1
SHARON ROBINSON: 1
MICHELLE CLARK: 1
LAURA RODRIGUEZ: 1
SARAH LEWIS: 1
KIMBERLY LEE: 1
DEBORAH WALKER: 1
JESSICA HALL: 1
SHIRLEY ALLEN: 1
CYNTHIA YOUNG: 1
ANGELA HERNANDEZ: 1
MELISSA KING: 1
BRENDA WRIGHT: 1
AMY LOPEZ: 1
ANNA HILL: 1
REBECCA SCOTT: 1
VIRGINIA GREEN: 1
KATHLEEN ADAMS: 1
PAMELA BAKER: 1
MARTHA GONZALEZ: 1
DEBRA NELSON: 1
AMANDA CARTER: 1

## ./countnames test/names_long_redundant2.txt

### $PID.err

### $PID.out

STEPHANIE MITCHELL: 1
CAROLYN PEREZ: 1
CHRISTINE ROBERTS: 1
MARIE TURNER: 1
JANET PHILLIPS: 1
CATHERINE CAMPBELL: 1
FRANCES PARKER: 1
ANN EVANS: 1
JOYCE EDWARDS: 1
DIANE COLLINS: 1
ALICE STEWART: 1
JULIE SANCHEZ: 1
HEATHER MORRIS: 1
TERESA ROGERS: 1
DORIS REED: 1
GLORIA COOK: 1
EVELYN MORGAN: 1
JEAN BELL: 1
CHERYL MURPHY: 1
MILDRED BAILEY: 1
KATHERINE RIVERA: 1
JOAN COOPER: 1
ASHLEY RICHARDSON: 1
JUDITH COX: 1
ROSE HOWARD: 1
JANICE WARD: 1
KELLY TORRES: 1
NICOLE PETERSON: 1
JUDY GRAY: 1
CHRISTINA RAMIREZ: 1
KATHY JAMES: 1
THERESA WATSON: 1
BEVERLY BROOKS: 1
DENISE KELLY: 1
TAMMY SANDERS: 1
IRENE PRICE: 1
JANE BENNETT: 1
LORI WOOD: 1
RACHEL BARNES: 1
MARILYN ROSS: 1
ANDREA HENDERSON: 1
KATHRYN COLEMAN: 1
LOUISE B JENKINS: 1
SARA A PERRY: 1

## ./countnames test/names_long_redundant3.txt

### $PID.err

### $PID.out

ANNE J POWELL: 1
JACQUELINE K LONG: 1
WANDA M PATTERSON: 1
BONNIE HUGHES: 1
JULIA FLORES: 1
RUBY WASHINGTON: 1
LOIS BUTLER: 1
TINA SIMMONS: 1
PHYLLIS FOSTER: 1
NORMA GONZALES: 1
PAULA BRYANT: 1
DIANA ALEXANDER: 1
ANNIE RUSSELL: 1
LILLIAN GRIFFIN: 1
EMILY DIAZ: 1
ROBIN HAYES: 1
MARY SMITH: 2
PATRICIA JOHNSON: 2
LINDA WILLIAMS: 2
BARBARA JONES: 2
ELIZABETH BROWN: 2
JENNIFER DAVIS: 1
MARIA MILLER: 1
SUSAN WILSON: 1
MARGARET MOORE: 1
DOROTHY TAYLOR: 1
LISA ANDERSON: 1
NANCY THOMAS: 1
KAREN JACKSON: 1
BETTY WHITE: 1
HELEN HARRIS: 1
SANDRA MARTIN: 1
DONNA THOMPSON: 1
CAROL GARCIA: 1
RUTH MARTINEZ: 1
SHARON ROBINSON: 1
MICHELLE CLARK: 1
LAURA RODRIGUEZ: 1
SARAH LEWIS: 1
KIMBERLY LEE: 1
DEBORAH WALKER: 1

## ./countnames test/testCase1.txt

### $PID.err

Warning - file test/testCase1.txt line 4 is empty.
Warning - file test/testCase1.txt line 6 is empty

### $PID.out

Mike Lam: 1
Jimmy Le: 1
J i m m y L e: 1
M ike Lam: 1
JeSsE: 1
JESSE: 1

## ./countnames test/testCase2.txt

### $PID.err

Warning - file test/testCase2.txt line 2 is empty.
Warning - file test/testCase2.txt line 6 is empty.
Warning - file test/testCase2.txt line 10 is empty.
Warning - file test/testCase2.txt line 14 is empty.

### $PID.out

Jose Mendez: 1
Ana Nguyen: 2
Charlie Kirk: 1
Barrack Obama: 1
Tommy Obama: 1
 : 1
 Tim Tran: 1
Andrew White: 2
ANDREW WHITE: 1
Nguyen Ana: 1

## ./countnames test/testCase3.txt

### $PID.err

Warning - file test/testCase3.txt line 6 is empty.
Warning - file test/testCase3.txt line 10 is empty.
Warning - file test/testCase3.txt line 13 is empty.
Warning - file test/testCase3.txt line 16 is empty.

### $PID.out

ABRAHAM LINCOLN: 1
ABRAHAM RAMIREZ: 1
 ABRAHAM LINCOLN: 1
ADRIAN ADRIAN: 1
ADRIAN: 1
JADA NGUYEn: 1
GEORGE WASHINGTON: 2
JADA NGUYEN: 1
JORGE PEREZ: 1
JESSE MENDOZA: 1
MENDOZA JESSE: 1

## Situations / Edge Cases:

- names.txt - Tests empty lines + duplicates + names with space
- names1.txt - Tests empty line + 1 repeated name
- names2.txt - Tests duplicates
- namesB.txt - Tests empty lines + duplicates
- names_long.txt - Tests many unique names + lines with one space
- names_long_redundant.txt - Tests many unique names with some duplicates
- names_long_redundant1.txt - Tests many unique names with a few empty lines 
- names_long_redundant2.txt - Tests many unique names
- names_long_redundant3.txt - Tests many unique names with some duplicates
- testCase1.txt - Tests spaces in between letters
- testCase2.txt - Tests empty lines + leading space + empty line with a space + case sensitivity
- testCase3.txt - Tests empty lines + same first name + leading space + duplicate

## Lessons Learned

Jada Lien Nguyen - This assignment helped me understand how to organize communication between parent and child processes. I learned how pipes can be used to return structured data, why file descriptor management matters when using dup2() and close(), and how small edge cases like empty lines or repeated names can affect the final merged result.


Jesse Mendoza - This assignment helped me learn fork(), execvp(), wait(), pipe(), and dup2(). I learned how the child processes can send data back to the parent through pipes, how the parent can merge the results from children, and how .err and .out files are created.


## References

- [Stack Overflow](https://stackoverflow.com): 
- Used to better understand string handling in C and file input functions like fgets() and fopen().
- Course materials: Lecture slides and notes from the SP26 course.
- [GNU Make Documentation](https://www.gnu.org/software/make/manual/make.html): For understanding Makefile syntax and usage.
- AI assistant (ChatGPT) — Used to clarify concepts related to string manipulation, input handling, and improving documentation wording.

## Acknowledgements

Thank you to the course instructor for the clear assignment guidelines. The class Discord was helpful for discussing edge cases. ZyBooks and reviewing the C textbook reinforced key concepts, and online resources and AI tools helped clarify specific implementation details.
