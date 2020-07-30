REM ------------------------------------ COMMON ENVIRONMENT VARIABLES ------------------------------------------
set ProjectDir=%1
set TargetName=%2
set Platform=%3
set ConfigName=%4
set TargetDir=%ProjectDir%\%Platform%\%ConfigName%
 
xcopy /f /y  %TargetDir%\ElementCommonLib.dll 	"%OutDirApps%\bin_debug\"
xcopy /f /y  %TargetDir%\ElementCommonLib.pdb 	"%OutDirApps%\bin_debug\"
xcopy /f /y  %TargetDir%\ElementCommonLib.lib 	"%OutDirApps%\lib_debug\"


REM - Element extension base classes

xcopy /f /y  ElementCommonLib.h  "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y  ElementCommonLibImportExport.h  "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y  ElementCommonLibVer.h  "%OutDirApps%\Inc\RecipeEditorCommonInc\"

xcopy /f /y  BaseRecipeExt.h  "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y  BaseAlignmentExt.h  "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y  BaseRunParametersExt.h  "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y  BaseSingleTestExt.h  "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y  BaseTestsExt.h  "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y  BaseWafermapExt.h  "%OutDirApps%\Inc\RecipeEditorCommonInc\"



REM - Doc\View\Frame base classes

REM - Recipe
xcopy /f /y RecipeDoc.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y RecipeFrame.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y RecipeView.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"

REM - Run-Parameters
xcopy /f /y ParametersDoc.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y ParametersFrm.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y ParametersView.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"

REM - Wafer-map
xcopy /f /y WaferMapDoc.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y WaferMapFrame.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y WaferMapView.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"

REM - Alignment
xcopy /f /y AlignmentDoc.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y AlignmentView.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y AlignmentFrm.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y BaseAlignmentImagePropertiesDlg.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y ComboListCtrl.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"

REM - Tests
xcopy /f /y TestsDoc.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y TestsFrame.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y TestsView.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"

REM - Single Test
xcopy /f /y SingleTestDoc.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y SingleTestFrm.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y ModifyTestView.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"


xcopy /f /y StaticWMEx.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"

xcopy /f /y EditWMEx.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"
xcopy /f /y OSPHelper.h "%OutDirApps%\Inc\RecipeEditorCommonInc\"