/* Stub for DTK hipBLASLt on BW100.
 * hipblasLtCreate() crashes inside createFusedMatmulKernelMap()/parseKernelName()
 * (std::regex bug) on the unsupported BW100 architecture.
 * torch only uses the hipBLASLt handle to read its version in
 * TuningResultsValidator; actual GEMM goes through hipBLAS/rocBLAS.
 * So we return a fake handle without initializing the real library. */
#include <string.h>
static void* fake_handle = (void*)0x1;
int hipblasLtCreate(void** handle) { *handle = fake_handle; return 0; }
int hipblasLtGetVersion(void* handle, int* version) { if (version) *version = 0; return 0; }
int hipblasLtGetGitRevision(void* handle, char* rev) { if (rev) { rev[0] = 's'; rev[1] = 't'; rev[2] = 'u'; rev[3] = 'b'; rev[4] = 0; } return 0; }
int hipblasLtDestroy(void* handle) { return 0; }
