/* Support for MPI parallelization.
 * 
 * SRE, Sat Jun  2 09:07:25 2007 [Janelia]
 * SVN $Id: esl_mpi.h 271 2008-06-20 13:12:58Z eddys $
 */

#if defined(HAVE_MPI) && defined(eslLIBRARY)
#ifndef eslMPI_INCLUDED
#define eslMPI_INCLUDED
#include "mpi.h"

#include "esl_alphabet.h"
#include "esl_msa.h"
#include "esl_stopwatch.h"

/* 1. Communicating optional arrays */
extern int esl_mpi_PackOpt(void *inbuf, int incount, MPI_Datatype type, void *pack_buf, 
			   int pack_buf_size, int *position, MPI_Comm comm);
extern int esl_mpi_PackOptSize(void *inbuf, int incount, MPI_Datatype type, MPI_Comm comm, int *ret_n);
extern int esl_mpi_UnpackOpt(void *pack_buf, int pack_buf_size, int *pos, void **outbuf, 
			     int *opt_n, MPI_Datatype type, MPI_Comm comm);

/* 2. Communicating ESL_MSA (multiple sequence alignments) */
extern int esl_msa_MPISend(const ESL_MSA *msa, int dest, int tag, MPI_Comm comm, char **buf, int *nalloc);
extern int esl_msa_MPIPackSize(const ESL_MSA *msa, MPI_Comm comm, int *ret_n);
extern int esl_msa_MPIPack(const ESL_MSA *msa, char *buf, int n, int *position, MPI_Comm comm);
extern int esl_msa_MPIUnpack(const ESL_ALPHABET *abc, char *buf, int n, int *pos, MPI_Comm comm, ESL_MSA **ret_msa);
extern int esl_msa_MPIRecv(int source, int tag, MPI_Comm comm, const ESL_ALPHABET *abc, char **buf, int *nalloc, ESL_MSA **ret_msa);

/* 3. Communicating ESL_STOPWATCH (process timing) */
extern int esl_stopwatch_MPIReduce(ESL_STOPWATCH *w, int root, MPI_Comm comm);


#endif /*eslMPI_INCLUDED*/
#endif /*HAVE_MPI && eslLIBRARY*/

/*****************************************************************
 *    This copyrighted source code is freely distributed 
 *    under the terms of the GNU General Public License. See
 *    the files COPYRIGHT and LICENSE for details.
 *****************************************************************/
