// Copyright 2005-2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the 'License');
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an 'AS IS' BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// See www.openfst.org for extensive documentation on this weighted
// finite-state transducer library.

#ifndef FST_SCRIPT_VERIFY_H_
#define FST_SCRIPT_VERIFY_H_

#include <fst/verify.h>
#include <fst/script/arg-packs.h>
#include <fst/script/fst-class.h>

namespace fst {
namespace script {

using VerifyArgs = WithReturnValue<bool, const FstClass &>;

template <class Arc>
void Verify(VerifyArgs *args) {
  const Fst<Arc> &fst = *args->args.GetFst<Arc>();
  args->retval = Verify(fst);
}

bool Verify(const FstClass &fst);

}  // namespace script
}  // namespace fst

#endif  // FST_SCRIPT_VERIFY_H_
