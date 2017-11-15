
// Sample AppicationView.cpp : implementation of the CSampleAppicationView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sample Appication.h"
#endif

#include "Sample AppicationDoc.h"
#include "Sample AppicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSampleAppicationView

IMPLEMENT_DYNCREATE(CSampleAppicationView, CView)

BEGIN_MESSAGE_MAP(CSampleAppicationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSampleAppicationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSampleAppicationView construction/destruction

CSampleAppicationView::CSampleAppicationView()
{
	// TODO: add construction code here

}

CSampleAppicationView::~CSampleAppicationView()
{
}

BOOL CSampleAppicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSampleAppicationView drawing

void CSampleAppicationView::OnDraw(CDC* /*pDC*/)
{
	CSampleAppicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSampleAppicationView printing


void CSampleAppicationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSampleAppicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSampleAppicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSampleAppicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSampleAppicationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSampleAppicationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSampleAppicationView diagnostics

#ifdef _DEBUG
void CSampleAppicationView::AssertValid() const
{
	CView::AssertValid();
}

void CSampleAppicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSampleAppicationDoc* CSampleAppicationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSampleAppicationDoc)));
	return (CSampleAppicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CSampleAppicationView message handlers
