#ifndef WINALTA_H
#define WINALTA_H
#include "wxfb_project.h"

class WinAlta : public WxfbProducto {
	
private:
	
protected:
	void OnClickCancelarProducto( wxCommandEvent& event )  override;
	void OnClickAltaoEditarProducto( wxCommandEvent& event )  override;
	
public:
	WinAlta(wxWindow *parent=NULL);
	~WinAlta();
};

#endif

