
#include "Repository.h"
#include "Medicine.h"

class MedicineRepo : public Repository {
public:
	MedicineRepo(bool sync = false);
	~MedicineRepo();

	Medicine* Get(int ind) { return (Medicine*)data[ind]; };
	void Show();

};