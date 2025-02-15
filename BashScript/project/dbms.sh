#!/bin/bash
 clear;
 echo "Welcome to DBMS using Bash Scripting language"
 sleep 1;
function mainMenu() {
   echo "================ Main Menu ==================="
   echo "| 1. Create Database   "
   echo "| 2. Select Database   "
   echo "| 3. Rename Database   "
   echo "| 4. Drop Database     "
   echo "| 5. Show Databases    "
   echo "| 6. Exit "
   echo "==================================="
   echo "Enter Choice : "
   
   read ch
   case $ch in
      1) createDB;;
      2) selectDB;;
      3) renameDB;;
      4) dropDB;;
      5) listDB;;
      6) exit;;
      *) echo "Invalid choice, please enter a valid option";sleep 1;mainMenu;;
   esac
}
function createDB() {
    local dbname="$1" ; 
    if [[ -z "$dbname" ]]; then
        echo -e "Enter Your Database Name to create: "
        read dbname
    fi
    if [[ -z "$dbname" ]]; then
        echo "Error: Database name cannot be empty!"
        return
    fi
    if [[ -d "./DBMS/$dbname" ]]; then
        echo "Database '$dbname' already exists!"
    else
        mkdir -p "./DBMS/$dbname"
        echo "Database '$dbname' created successfully."
    fi
    sleep 2
    mainMenu  
}

function listDB(){
	echo "Available Databases:"
	ls ./DBMS
	sleep 1.5
       	mainMenu
}

function selectDB(){
    echo "Enter Database name to select : "
    read dbname
    cd ./DBMS/$dbname 2>> ./errors.log
    if [[ $? == 0 ]];then
        echo "Database $dbname has selected successfully"
	sleep 2
	clear
	echo "===================  $dbname Database ===================="
        dbTables
    else
       echo "Database $dbname wasn't found"
       sleep 1
       mainMenu
    fi
}
function dropDB() {
    echo "Enter DataBase Name to drop : "
    read dbname;
    rm -r ./DBMS/$dbname 2>>./errors.log
    if [[ $? == 0 ]];then
       echo "Database deleted sucessfully"
    else 
      echo "Databse Not Found"
    fi
    sleep 1
    mainMenu  
}
function renameDB() {
   echo "Enter Database Name to rename : "
   read oldname;
   if [[ -d "./DBMS/$oldname" ]]; then
	echo "Enter New Database Name : "
   	read newname;
        if [[ ! -d "./DBMS/$newname" ]]; then
            mv "./DBMS/$oldname" "./DBMS/$newname"
            echo "Database renamed from $oldname to $newname."
        else
            echo "Database with the new name already exists!"
  	 fi
    else
   	echo "Error: Database $oldName does not exist!"
   fi
   sleep 1
   mainMenu   
}
function dbTables(){
     echo   "=========== Tables Menu ============"
     echo "| 1. Show Existing Tables "
     echo "| 2. Create New Table   "
     echo "| 3. Insert Into Table "
     echo "| 4. Select From Table "
     echo "| 5. Update Table "
     echo "| 6. Delete From Table "
     echo "| 7. Drop a Table"
     echo "| 8. Back to Main Menu"
     echo "| 9. Display Table"
     echo "| 10. Exit"
     echo "====================================="

    echo "Enter Your Choise : "
    read ch
    case $ch in 
       1) showTables;;
       2) createTable;;
       3) insertIntoTable;;
       4) clear ; selectMenu;;
       5) updateTable;;
       6) deleteFromTable;;
       7) dropTable;;
       8)clear ; cd ../.. 2>>./errors.log;mainMenu;;
       9) displayTable ;;
       10)clear;exit;;
       *) echo "wrong choise";dbTables;
   esac
}
function showTables(){
    if [ -z "$(ls -A)" ]; then
        echo "No tables found in the current database."
    else
        echo "Tables in the current database:"
        ls
    fi
    sleep 1
    dbTables
}

function createTable(){
    echo -n "Enter Table Name: "
    read tableName
    
    # Validate table name (should not be empty or contain spaces)
    if [[ -z "$tableName" || "$tableName" =~ [[:space:]] ]]; then
        echo "Invalid table name! It cannot be empty or contain spaces."
        echo "Error: Failed to create table "
       	sleep 1
	dbTables
        return
    fi

    # Check if table already exists
    if [[ -f "$tableName" ]]; then
        echo "Error: Table '$tableName' already exists!"
	echo "Error: Failed to create table "
        sleep 1
        dbTables
        return
    fi

    echo -n "Enter Number of Columns: "
    read colsNum

    # Validate column number input
    if ! [[ "$colsNum" =~ ^[1-9][0-9]*$ ]]; then
        echo "Invalid column number! Please enter a positive integer."
        sleep 1
        dbTables
        return
    fi

    counter=1
    sep="|"
    rSep="\n"
    pKey=""
    metaData="Field${sep}Type${sep}Key"
    temp=""
    declare -A columnNames  # To store column names and prevent duplicates

    while [ $counter -le $colsNum ]; do
        echo -n "Enter Name of Column No.$counter: "
        read colName

        # Validate column name (should not be empty, contain spaces, or be duplicate)
        if [[ -z "$colName" || "$colName" =~ [[:space:]] || ${columnNames[$colName]+_} ]]; then
            echo "Invalid column name! It must be unique, not empty, and contain no spaces."
            continue
        fi

        columnNames[$colName]=1  # Mark column as used

        echo "Choose Type for Column $colName:"
        select var in INT TEXT; do
            case $var in
                INT) colType="INT"; break ;;
                TEXT) colType="TEXT"; break ;;
                *) echo "Invalid choice! Please select again." ;;
            esac
        done

        # Assign primary key if not set
        if [[ -z "$pKey" ]]; then
            echo "Do you want to make this column a primary key?"
            select var in "YES" "NO"; do
                case $var in
                    YES) pKey="PK"; metaData+="$rSep$colName$sep$colType$sep$pKey"; break ;;
                    NO) metaData+="$rSep$colName$sep$colType$sep"; break ;;
                    *) echo "Invalid choice! Please select again." ;;
                esac
            done
        else
            metaData+="$rSep$colName$sep$colType$sep"
        fi

        # row format
        temp+="$colName"
        [[ $counter -lt $colsNum ]] && temp+="$sep"

        ((counter++))
    done

    # Create metadata and data files
    echo -e "$metaData" > ".$tableName"
    echo -e "$temp" > "$tableName"

    if [[ $? -eq 0 ]]; then
        echo "Table '$tableName' Created Successfully!"
    else
        echo "Error: Failed to create table '$tableName'."
    fi
    
    sleep 2
    clear
    dbTables
}

function insertIntoTable(){
  if [ -z "$(ls -A)" ]; then
        echo "No tables found in the current database to insert into."
	dbTables
    else
        echo "Available tables in the current database:"
        ls
    fi  
  echo -e "Enter Table Name: \c"
  read tableName

  # Check if table exists
  if [[ ! -f $tableName ]]; then
    echo "Table does not exist!"
    sleep 1
    dbTables
  fi

  # Load metadata
  metaDataFile=".$tableName"
  if [[ ! -f $metaDataFile ]]; then
    echo "Metadata file is missing! Cannot insert data."
    sleep 1
    dbTables
  fi

  # Read column headers from metadata
  IFS=$'\n' read -d '' -r -a columns < <(tail -n +2 "$metaDataFile")

  counter=1
  rowData=""
  sep="|"
  primaryKeyValue=""

  for column in "${columns[@]}"; do
    IFS='|' read -r colName colType colKey <<< "$column"

    # Ask for column value
    echo -e "Enter value for Column No.$counter ($colName - $colType): \c"
    read value

    # Validate data type
    case $colType in
      INT)
        if [[ ! "$value" =~ ^[0-9]+$ ]]; then
          echo "Cannot insert data: $colName must be an integer!"
	  sleep 1
          dbTables
        fi
        ;;
      TEXT)
        if [[ -z "$value" ]]; then
          echo "Cannot insert data: $colName cannot be empty!"
	  sleep 1
          dbTables
        fi
        ;;
      *)
        echo "Cannot insert data.: Unknown column type!"
	sleep 1
        dbTables
        ;;
    esac

    # Check for primary key uniqueness
    if [[ "$colKey" == "PK" ]]; then
      primaryKeyValue="$value"
      if grep -q "^$primaryKeyValue$sep" "$tableName"; then
        echo "Error: Primary key value '$primaryKeyValue' already exists!"
        dbTables
      fi
    fi

    # Format row data
    if [[ $counter -eq ${#columns[@]} ]]; then
      rowData+="$value"
    else
      rowData+="$value$sep"
    fi

    ((counter++))
  done

  # Insert row into table
  echo "$rowData" >> "$tableName"
  echo "Data inserted successfully into $tableName."
  dbTables
}

function updateTable(){
    if [ -z "$(ls -A)" ]; then
        echo "No tables found in the current database."
        sleep 1
        dbTables
    fi

    echo "Available tables in the current database:"
    ls
    echo -n "Enter Table Name: "
    read tableName

    while [[ ! -f $tableName ]]; do
        echo "Table does not exist! Please enter a valid table name."
        read tableName
    done

    metaDataFile=".$tableName"
    dataFile="$tableName"

    # Read metadata
    mapfile -t columns < <(tail -n +2 "$metaDataFile")

    # Extract primary key column
    pKeyColumn=""
    pKeyIndex=-1
    IFS="|" read -ra headers <<< "$(head -n 1 "$dataFile")"

    for i in "${!columns[@]}"; do
        IFS="|" read -ra col <<< "${columns[i]}"
        if [[ "${col[2]}" == "PK" ]]; then
            pKeyColumn="${col[0]}"
            pKeyIndex=$i
            break
        fi
    done

    if [[ -z "$pKeyColumn" ]]; then
        echo "No primary key found! Cannot update records."
        sleep 1
        dbTables
    fi
    
# Show all primary key values
    echo "Existing $pKeyColumn values:"
    awk -F"|" -v col=$((pKeyIndex+1)) 'NR>1 {print $col}' "$dataFile"

    echo -n "Enter $pKeyColumn value to update: "
    read pKeyValue

    # Validate primary key existence
    recordLine=$(awk -v key="$pKeyValue" -F"|" -v col=$((pKeyIndex+1)) '$col == key {print NR}' "$dataFile")

    while [[ -z "$recordLine" ]]; do
        echo "Record with $pKeyColumn = $pKeyValue not found! Enter a valid value."
        read pKeyValue
        recordLine=$(awk -v key="$pKeyValue" -F"|" -v col=$((pKeyIndex+1)) '$col == key {print NR}' "$dataFile")
    done

    # Display current record
    echo "Current record: $(sed -n "${recordLine}p" "$dataFile")"

    newRecord=""
    for ((i = 0; i < ${#columns[@]}; i++)); do
        IFS="|" read -r colName colType isKey <<< "${columns[i]}"

        echo -n "Enter new value for $colName (leave empty to keep current value): "
        read newValue

        # Keep existing value if input is empty
        if [[ -z "$newValue" ]]; then
            IFS="|" read -ra oldValues <<< "$(sed -n "${recordLine}p" "$dataFile")"
            newValue="${oldValues[i]}"
        fi

        # Validate data type
        while [[ "$colType" == "INT" && ! "$newValue" =~ ^[0-9]+$ ]]; do
            echo "Invalid input! $colName must be an integer. Enter a valid value:"
            read newValue
        done

        if [[ $i -eq $((${#columns[@]} - 1)) ]]; then
            newRecord+="$newValue"
        else
            newRecord+="$newValue|"
        fi
    done

    # Update the record
    sed -i "${recordLine}s/.*/$newRecord/" "$dataFile"
    echo "Record updated successfully."
    sleep 1
    dbTables
}


function deleteFromTable(){
    if [ -z "$(ls -A)" ]; then
        echo "No tables found in the current database."
        sleep 1
        dbTables
    fi

    echo "Available tables in the current database:"
    ls
    echo -n "Enter Table Name: "
    read tableName

    while [[ ! -f $tableName ]]; do
        echo "Table does not exist! Please enter a valid table name."
        read tableName
    done

    metaDataFile=".$tableName"
    dataFile="$tableName"

    # Read metadata
    mapfile -t columns < <(tail -n +2 "$metaDataFile")

    # Extract primary key column
    pKeyColumn=""
    pKeyIndex=-1
    IFS="|" read -ra headers <<< "$(head -n 1 "$dataFile")"

    for i in "${!columns[@]}"; do
        IFS="|" read -ra col <<< "${columns[i]}"
        if [[ "${col[2]}" == "PK" ]]; then
            pKeyColumn="${col[0]}"
            pKeyIndex=$i
            break
        fi
    done

    if [[ -z "$pKeyColumn" ]]; then
        echo "No primary key found! Cannot delete records."
        sleep 1
        dbTables
    fi

    # Show all primary key values
    echo "Existing $pKeyColumn values:"
    awk -F"|" -v col=$((pKeyIndex+1)) 'NR>1 {print $col}' "$dataFile"

    echo -n "Enter $pKeyColumn value to delete: "
    read pKeyValue

    # Validate primary key existence
    recordLine=$(awk -v key="$pKeyValue" -F"|" -v col=$((pKeyIndex+1)) '$col == key {print NR}' "$dataFile")

    while [[ -z "$recordLine" ]]; do
        echo "Record with $pKeyColumn = $pKeyValue not found!"
        echo "Existing $pKeyColumn values:"
        awk -F"|" -v col=$((pKeyIndex+1)) 'NR>1 {print $col}' "$dataFile"
        echo -n "Enter a valid $pKeyColumn value: "
        read pKeyValue
        recordLine=$(awk -v key="$pKeyValue" -F"|" -v col=$((pKeyIndex+1)) '$col == key {print NR}' "$dataFile")
    done

    # Confirm deletion
    echo "Are you sure you want to delete this record? (yes/no)"
    read confirmation
    if [[ "$confirmation" == "yes" ]]; then
        sed -i "${recordLine}d" "$dataFile"
        echo "Record deleted successfully."
    else
        echo "Deletion canceled."
    fi

    sleep 1
    dbTables
}

function dropTable(){
    if [ -z "$(ls -A)" ]; then
        echo "No tables found in the current database."
        sleep 1
        dbTables
    fi

    echo "Available tables in the current database:"
    ls

    echo -n "Enter Table Name to Drop: "
    read tableName

    while [[ ! -f $tableName ]]; do
        echo "Table does not exist! Please enter a valid table name."
        read tableName
    done

    echo -n "Are you sure you want to drop the table '$tableName'? (yes/no): "
    read confirmation
    if [[ "$confirmation" != "yes" ]]; then
        echo "Operation canceled."
        sleep 1
        dbTables
    fi

    rm -f "$tableName" ".$tableName"
    echo "Table '$tableName' dropped successfully."
    sleep 1
    dbTables
}


function displayTable() {
      if [ -z "$(ls -A)" ]; then
        echo "No tables found in the current database."
        sleep 1
        dbTables
    fi

    echo "Available tables in the current database:"
    ls
      echo "Enter Table Name : "
      read tablName
      if [ ! -f $tablName ];then
         echo "Table Not found"
         dbTables
      fi
      echo "Table Schema: "
      cat .$tableName
      echo "Table Data: "
      cat $tableName
      sleep 2
      dbTables

}
function selectMenu(){
    echo "=========== Select Menu ============"
    echo "| 1. Select All Records "
    echo "| 2. Select All Records in Column "
    echo "| 3. Select All Data by equal Condition "
    echo "| 4. Back to Tables Menu"
    echo "====================================="

    echo -n "Enter Your Choice: "
    read choice

    case $choice in
        1) selectAllRecords ;;
        2) selectByColumn ;;
        3) selectByCondition ;;
        4)clear; dbTables ;;
        *) echo "Invalid choice! Please try again.";sleep 1; selectMenu ;;
    esac
}

function selectAllRecords(){
    echo -n "Enter Table Name: "
    read tableName

    if [[ ! -f $tableName ]]; then
        echo "Table does not exist!"
        selectMenu
    fi

    echo "===== Data from $tableName ====="
    column -t -s '|' "$tableName"   # Display data in table format
    echo "================================"
    selectMenu
}

function selectByColumn(){
    echo -n "Enter Table Name: "
    read tableName

    if [[ ! -f $tableName ]]; then
        echo "Table does not exist!"
        selectMenu
    fi

    echo "Available Columns: "
    head -n 1 "$tableName" | tr '|' '\n'  # Show column names

    echo -n "Enter column name to select: "
    read columnName

    # Find column index
    colIndex=$(head -n 1 "$tableName" | tr '|' '\n' | grep -nx "$columnName" | cut -d: -f1)

    if [[ -z "$colIndex" ]]; then
        echo "Invalid column name!"
        selectMenu
    fi

    echo "===== Data from Column: $columnName ====="
    cut -d '|' -f "$colIndex" "$tableName"  # Extract selected column
    echo "========================================="
    selectMenu
}


function selectByCondition(){
    echo -n "Enter Table Name: "
    read tableName

    if [[ ! -f $tableName ]]; then
        echo "Table does not exist!"
        selectMenu
    fi

    echo "Available Columns: "
    head -n 1 "$tableName" | tr '|' '\n'

    echo -n "Enter column name to filter by: "
    read columnName

    colIndex=$(head -n 1 "$tableName" | tr '|' '\n' | grep -nx "$columnName" | cut -d: -f1)

    if [[ -z "$colIndex" ]]; then
        echo "Invalid column name!"
        selectMenu
    fi

    echo -n "Enter value to match: "
    read value

    echo "===== Filtered Records ====="
    awk -F '|' -v col="$colIndex" -v val="$value" '$col == val' "$tableName"
    echo "==========================="
    selectMenu
}

mainMenu
