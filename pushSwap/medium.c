#include "pushswap.h"
#include <stdio.h>

/*============ Find moove ==================*/






/*=============== Chunk sort =================*/

// Étape 2 — Indexation (compression de coordonnées)
// But : attribuer à chaque nœud un idx = rang trié entre 0 et n-1.
// 2.1 Algorithme

// Copier toutes les valeurs de A dans un tableau arr[n].
// qsort(arr) (ordre croissant).
// Pour chaque nœud de A, trouver sa position dans arr → écrire dans node->idx.


// Astuce : si tu veux O(n log n) propre, fais une recherche binaire.
// Pour n ≤ 500, une simple boucle O(n^2) reste acceptable.

// 2.2 Tests rapides

// Avec A = [40, 10, 30, 20, 50] :

// Trié : [10, 20, 30, 40, 50]
// idx(A) devrait devenir : [3, 0, 2, 1, 4].



// Pièges :

// Doublons → interdit (gère l’erreur avant).
// Ne modifie jamais data ici ; on écrit idx.

// Étape 3 — Construire les chunks (plages d’indices)
// Un chunk = intervalle [lo, hi] sur les indices.
// 3.1 Choisir le nombre de chunks k

// n ≤ 100 → k = 5 à 7 (commence à 5)
// n ≤ 500 → k = 11 à 13 (commence à 11)

// 3.2 Générer les plages

// Répartir 0..n-1 en k paquets presque égaux.
// Exemple avec n=100, k=5 → tailles ≈ 20 :

// C1: [0..19], C2: [20..39], ..., C5: [80..99].



// À coder :

// Range { int lo, hi; }
// build_chunks(n, &k) retourne un tableau Range*.

// Test :

// Afficher les plages pour vérifier (en dev).

// Étape 4 — Phase A → B : pousser chunk par chunk
// 4.1 Helpers nécessaires

// exists_in_chunk(A, Range r) → 1 si un nœud de A a idx ∈ [lo,hi].
// pos_from_top(A, r) → première position (0-based) d’un idx dans la plage.
// pos_from_bottom(A, r) → distance depuis le bas (0 = dernier).
// rotate_min_to_top(&A, r) :

// calcule top vs bot et effectue soit ra x top, soit rra x bot (le moins cher).



// 4.2 Boucle principale A→B
// Pour chaque chunk r :

// Tant que exists_in_chunk(A, r) :

// rotate_min_to_top(&A, r)
// pb(&A, &B)
// Orienter B (option simple mais efficace) :

// Calculer mid = r.lo + (r.hi - r.lo)/2
// Si l’élément poussé ((*B)->idx) est > mid, faire rb(&B)
// → ça force une pile B “descendante” (les plus grands remontent facilement ensuite).





// 4.3 Tests & debug

// Sur un petit jeu (10–20 éléments) : tracer les idx déplacés.
// Vérifier que B grossit chunk après chunk.
// Tu dois voir B s’organiser approximativement du plus grand vers le haut (grâce à l’orientation).

// Pièges :

// N’oublie jamais les gardes : if (!A || !*A) return; avant pb, etc.
// Attention à ne pas confondre ra (pile A) et rb (pile B).


// Étape 5 — Phase B → A : insertion “cheapest cost”
// Le cœur “medium+” : choisir à chaque tour l’élément de B qui coûte le moins de moves pour être inséré dans A au bon endroit, et fusionner les rotations si possible (rr/rrr).
// 5.1 Trouver la position cible dans A pour un bidx
// On veut insérer bidx entre deux indices consécutifs dans A.
// Cas :

// Si bidx < min(A) ou bidx > max(A) → cible = position du min(A) (car A est circulaire).
// Sinon, parcours A pour trouver A[i].idx < bidx < A[i+1].idx → cible = i+1.

// À écrire :

// min_idx(A), max_idx(A), pos_target_in_A(A, bidx).

// 5.2 Calculer les coûts de rotations
// Pour un élément à la position posB dans B :

// costB = rot_cost(posB, sizeB)

// rot_cost(pos, n) retourne :

// +k si k rotations (rb) suffisent (pos en haut par le haut),
// -k si k reverse rotations (rrb) coûtent moins.




// target = pos_target_in_A(A, bidx)
// costA = rot_cost(target, sizeA)

// Fusion :

// Si costA et costB ont le même signe (tous deux >=0 ou <0) :

// On peut faire des rr (ou rrr) pour min(costA, costB) rotations,
// Puis finir séparément (reste de ra/rb ou rra/rrb).


// Sinon, on additionne simplement abs(costA) + abs(costB).

// À écrire :

// compute_cost_for_bpos(A, B, posB) → renvoie costA, costB, total, targetA, posB.
// choose_cheapest(A, B) → boucle sur tous les posB et garde le total minimal.

// 5.3 Exécuter les rotations combinées + pa

// while (costA>0 && costB>0) rr(&A,&B), costA--, costB--;
// while (costA<0 && costB<0) rrr(&A,&B), costA++, costB++;
// Finir A seul (ra/rra) puis B seul (rb/rrb).
// Enfin pa(&A, &B).

// 5.4 Répéter jusqu’à ce que B soit vide
// Boucle :
// while (B != NULL) {
//   c = choose_cheapest(A,B);
//   do_rotations(A,B,c);
//   pa(&A,&B);
// }

// 5.5 Finalisation

// Amener idx == 0 (le plus petit) en haut de A par rotation minimale (ra vs rra).




// int main(void)
// {
// 	int size = 10;
// 	Stack *stackB = NULL;
// 	Stack *stackA = NULL;
// 	int *arr = (int *)malloc(sizeof(int) * size);
// 	if (arr == NULL)
// 		return printf("Memory not alloctaed\n");
// 	int i = 0;
// 	while(i < size)
// 	{
// 		arr[i] = i;
// 		i ++;
// 	}
//     randomize (arr, size);
// 	i = 0;
// 	while(i < size)
// 	{
// 		push(&stackA, arr[i]);
// 		i ++;
// 	}
// 	printf("Disorder = %f\n", compute_disorder(stackA));

// 	mediumSort(&stackA, &stackB);
// 	printf("Disorder = %f\n", compute_disorder(stackA));
// 	return 0;
	
// }

